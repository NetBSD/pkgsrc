#!@SH@
#
# $NetBSD: monotone-server-init.sh,v 1.5 2010/03/07 22:09:36 jmmv Exp $
#

progname=$(basename $0)

MONOTONE=@MONOTONE@
MONOTONE_GROUP=@MONOTONE_GROUP@
MONOTONE_USER=@MONOTONE_USER@
PKG_SYSCONFDIR=@PKG_SYSCONFDIR@
VARBASE=@VARBASE@

if [ $(id -u) -ne 0 ]; then
    echo "${progname}: this program must be run as \`root'" 1>&2
    exit 1
fi

cat <<EOF
The following user and group will be used to run the monotone server
process under a restricted account:

    User name \`${MONOTONE_USER}', UID \``id -u monotone`'
    Group name \`${MONOTONE_GROUP}', GID \``id -g monotone`'

If either the UID or the GID are inappropriate, please abort this
script now, correct them and restart the utility so that all the
files are created with the correct ownerships.

Press RETURN to continue or CTRL-C to abort.
EOF
read key

cat <<EOF
The monotone package is currently configured to use the
${VARBASE}/monotone directory to hold the public database.
You may now change this default path to something else that is
more suitable for your system, if you wish.

EOF

printf "Enter home directory [${VARBASE}/monotone]: "
read home
: ${home:=${VARBASE}/monotone}

if [ ${home} != ${VARBASE}/monotone ]; then

    if ! usermod -d ${home} ${MONOTONE_USER}; then
        echo "cannot modify home directory of user " \
             "\`${MONOTONE_USER}'" 1>&2
        exit 1
    fi

    echo "monotone_home=${home}" >>${PKG_SYSCONFDIR}/rc.conf
fi

cat <<EOF

In order to serve a collection, you must now create a public/private key
pair to access the database.  This has to be _different_ to the key pair
you use for development; it will only be used by the server process.

The key name should be in the form of an email address.  Typicall, it will
be something like monotone@your_host_name.

I have determined that monotone@$(hostname) is probably a good choice.

EOF
printf "Enter key name [monotone@$(hostname)]: "
read keyname
: ${keyname:=monotone@$(hostname)}

if [ ! -d ${home} ]; then
    echo "Initializing new home directory: \`${home}'"
    mkdir -p ${home}
    chmod 755 ${home}
    chown ${MONOTONE_USER}:${MONOTONE_GROUP} ${home}
fi

cd ${home}

echo "Initializing database: \`${home}/monotone.db'"
su - ${MONOTONE_USER} -c "${MONOTONE} --confdir=${PKG_SYSCONFDIR} \
    --db=monotone.db --keydir=${PKG_SYSCONFDIR}/keys db init"

cat <<EOF

Monotone will now ask you for a passphrase to protect the key pair we are
creating.  Choose a hard one and write it down temporarily; you will need
to put it in one of the configuration files in a later step.  After that,
you can forget about it (assuming you have a safe copy).

EOF

su - ${MONOTONE_USER} -c "${MONOTONE} --confdir=${PKG_SYSCONFDIR} \
    --db=monotone.db --keydir=${PKG_SYSCONFDIR}/keys \
    genkey ${keyname}"

chown ${MONOTONE_USER}:${MONOTONE_GROUP} monotone.db
chmod 600 monotone.db

cat <<EOF

Initialization process finished!

You should now backup the following file and store it in a safe place.
It contains the key pair that authenticates your server:

    ${PKG_SYSCONFDIR}/keys/${keyname}

Then, edit the following files to finish the configuration of your new
server:

    ${PKG_SYSCONFDIR}/hooks.conf
    ${PKG_SYSCONFDIR}/read-permissions
    ${PKG_SYSCONFDIR}/write-permissions

At last, do not forget to register the public keys for the users with
write access by using a command similar to:

    ${MONOTONE##*/} --db=${home}/monotone.db read < file-with-public-keys

Once finished, use the installed rc.d script (monotone) to start the
dedicated server process.
EOF

exit 0
