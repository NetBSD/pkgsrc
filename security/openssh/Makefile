# $NetBSD: Makefile,v 1.60 2001/12/03 08:21:21 martti Exp $

DISTNAME=		openssh-3.0.2p1
PKGNAME=		openssh-3.0.2.1
SVR4_PKGNAME=		ossh
CATEGORIES=		security
MASTER_SITES=		ftp://gd.tuwien.ac.at/OpenBSD/OpenSSH/portable/ \
			ftp://ftp.openssh.com/pub/OpenBSD/OpenSSH/portable/ \
			ftp://ftp.openssh.com/pub/OpenBSD/OpenSSH/portable/old/
# Don't delete the last entry -- it's there if the pkgsrc version is not
# up-to-date and the mirrors already removed the old distfile.

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.openssh.com/
COMMENT=		Open Source Secure shell client and server (remote login program)

CONFLICTS=		sftp-[0-9]*
CONFLICTS+=		ssh-[0-9]* ssh6-[0-9]*

BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5

CRYPTO=			yes

# retain the following line, for IPv6-ready pkgsrc webpage 
BUILD_DEFS+=		USE_INET6
#BUILD_DEFS+=		KERBEROS
BUILD_DEFS+=		SSH_CONF_DIR
BUILD_DEFS+=		SSH_SUID

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

# matches what's in `Configure' (except sparc64 and alpha, see PR 10984)
ONLY_FOR_PLATFORM=	NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-m68k NetBSD-*-mips NetBSD-*-mipseb \
			NetBSD-*-mipsel NetBSD-*-ns32k NetBSD-*-powerpc \
			NetBSD-*-sparc NetBSD-*-vax SunOS-*-* Linux-*-*

.include "../../mk/bsd.prefs.mk"

SSH_CONF_DIR?=		/etc

MESSAGE_SUBST+=		SSH_CONF_DIR=${SSH_CONF_DIR}

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${SSH_CONF_DIR}
CONFIGURE_ARGS+=	--with-ssl-dir=${BUILDLINK_DIR}

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-tcp-wrappers
# XXX: we have 4 args (4: sslen) to skeychallenge instead of 3
#CONFIGURE_ARGS+=	--with-skey=/usr
.endif

# XXX: <krb.h>
#.if defined(KERBEROS)
#USE_KERBEROS=		yes
#CONFIGURE_ARGS+=	--with-kerberos4=/usr
#.endif

# Don't install "ssh" setuid
.if !defined(SSH_SUID) || ${SSH_SUID} != YES
CONFIGURE_ARGS+=	--disable-suid-ssh
.endif

# Solaris normaly doesn't have a /var/run, thats why we put it in /etc
.if (${OPSYS} == SunOS)
CONFIGURE_ARGS+=	--with-pid-dir=/etc
SSH_PID_DIR=		/etc
.else
SSH_PID_DIR=		/var/run
.endif

# The ssh-askpass program is in ${X11BASE}/bin or ${X11PREFIX}/bin depending
# on if it's part of the X11 distribution, or if it's installed from pkgsrc
# (security/ssh-askpass).  The configure process will lie about the compiled
# location of the ssh-askpass program.  In reality, it uses what we give it
# below.
#
.if exists(${X11BASE}/bin/ssh-askpass)
MAKE_ENV+=		ASKPASS_PROGRAM=${X11BASE}/bin/ssh-askpass
.else
MAKE_ENV+=		ASKPASS_PROGRAM=${X11PREFIX}/bin/ssh-askpass
.endif

CHECK_FILES=	bin/slogin man/man1/slogin.1 \
		share/examples/openssh/ssh_prng_cmds
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

.if (${OPSYS} == SunOS)
INSTALL_FILE=		${WRKDIR}/INSTALL.SunOS
.endif

#post-patch:
#	cd ${WRKSRC} ; autoreconf --force

post-build:
	for FILE in \
		${PKGDIR}/DEINSTALL	\
		${PKGDIR}/INSTALL	\
		${PKGDIR}/INSTALL.SunOS	\
		${FILESDIR}/sshd.sh;	\
	do \
		${SED}	-e 's#@SSH_CONF_DIR@#${SSH_CONF_DIR}#g' \
			-e 's#@SSH_PID_DIR@#${SSH_PID_DIR}#g' \
			-e 's#@MKDIR@#${MKDIR}#g' \
			-e 's#@PREFIX@#${PREFIX}#g' \
			-e 's#@INSTALL_DATA@#${INSTALL_DATA}#g' \
			< $${FILE} > ${WRKDIR}/`basename $${FILE}`; \
	done

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sshd.sh ${PREFIX}/etc/rc.d/sshd
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	cd ${PREFIX}; \
	for FILE in ${CHECK_FILES}; do \
	  if [ ! -f $${FILE} ]; then \
	    ${MV} ${PLIST_SRC} ${PLIST_SRC}.old; \
	    ${GREP} -v "^$${FILE}" ${PLIST_SRC}.old >${PLIST_SRC}; \
	    ${RM} ${PLIST_SRC}.old; \
	  fi; \
	done

.include "../../devel/zlib/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
