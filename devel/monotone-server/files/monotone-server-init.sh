#!@SH@
#
# $NetBSD: monotone-server-init.sh,v 1.1.1.1 2005/01/12 12:52:50 jmmv Exp $
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

echo "Initializing database: \`${home}'/monotone.db"
${MONOTONE} --db=monotone.db db init

cat <<EOF

Monotone will now ask you for a passphrase to protect the key pair we are
creating.  Choose a hard one and write it down temporarily; you will need
to put it in one of the configuration files in a later step.  After that,
you can forget about it (assuming you have a safe copy).

EOF

${MONOTONE} --db=monotone.db genkey ${keyname}
${MONOTONE} --db=monotone.db pubkey ${keyname} >${keyname}-public
${MONOTONE} --db=monotone.db privkey ${keyname} >${keyname}-private

chown ${MONOTONE_USER}:${MONOTONE_GROUP} monotone.db \
      ${keyname}-public ${keyname}-private
chmod 600 monotone.db
chmod 444 ${keyname}-public
chmod 400 ${keyname}-private

cat <<EOF

Initialization process finished!

You should now backup the following files and store them in a safe place
in case you need to reconstruct the database from scratch:

    ${home}/${keyname}-public
    ${home}/${keyname}-private

At last, edit the following files to finish the configuration of your
new server:

    ${PKG_SYSCONFDIR}/branches.conf
    ${PKG_SYSCONFDIR}/hooks.conf

Once finished, use the installed rc.d script (monotone) to start the
dedicated server process.
EOF

exit 0
