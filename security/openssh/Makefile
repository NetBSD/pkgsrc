# $NetBSD: Makefile,v 1.91 2002/09/19 09:04:22 jlam Exp $

DISTNAME=		openssh-3.4p1
PKGNAME=		openssh-3.4.0.1
SVR4_PKGNAME=		ossh
CATEGORIES=		security
#MASTER_SITES=		ftp://gd.tuwien.ac.at/opsys/OpenBSD/OpenSSH/portable/ \
#			ftp://ftp.openssh.com/pub/OpenBSD/OpenSSH/portable/ \
#			ftp://ftp.openssh.com/pub/OpenBSD/OpenSSH/portable/old/
# Don't delete the last entry -- it's there if the pkgsrc version is not
# up-to-date and the mirrors already removed the old distfile.

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.openssh.com/
COMMENT=		Open Source Secure shell client and server (remote login program)

CONFLICTS=		sftp-[0-9]*
CONFLICTS+=		ssh-[0-9]* ssh6-[0-9]*

USE_PERL5=		build

# 0.9.5a can be used, with blowfish support broken.  so require 0.9.6.
USE_OPENSSL_VERSION=	${OPENSSL_VERSION_096}

CRYPTO=			yes

# retain the following line, for IPv6-ready pkgsrc webpage 
BUILD_DEFS+=		USE_INET6
#BUILD_DEFS+=		KERBEROS

.include "../../mk/bsd.prefs.mk"

INSTALL_TARGET=		install-nokeys
PLIST_SRC=		# empty
MESSAGE_SRC=		${.CURDIR}/MESSAGE

PKG_USERS=		${OPENSSH_USER}:${OPENSSH_GROUP}:${OPENSSH_UID}:sshd\\ privsep:${OPENSSH_CHROOT}:${NOLOGIN}
PKG_GROUPS=             ${OPENSSH_GROUP}:${OPENSSH_GID}

SSH_PID_DIR=		/var/run	# default directory for PID files

PKG_SYSCONFSUBDIR=	ssh
MANDIR=			man
RCD_SCRIPTS_EGDIR=	etc/rc.d

PLIST_SUBST+=		MANDIR=${MANDIR}
PLIST_SUBST+=		RCD_SCRIPTS_EGDIR=${RCD_SCRIPTS_EGDIR}

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${MANDIR}
CONFIGURE_ARGS+=	--with-pid-dir=${SSH_PID_DIR}
CONFIGURE_ARGS+=	--with-ssl-dir=${SSLBASE}
CONFIGURE_ARGS+=	--with-tcp-wrappers=${BUILDLINK_PREFIX.tcp_wrappers}
CONFIGURE_ARGS+=	--with-privsep-path=${OPENSSH_CHROOT}
CONFIGURE_ARGS+=	--with-privsep-user=${OPENSSH_USER}

# XXX: PAM authentication causes memory faults, and I haven't tracked down
# XXX: why yet.  For the moment, disable PAM authentication.
#
#.if defined(USE_PAM)
#.include "../../security/PAM/buildlink2.mk"
#CONFIGURE_ARGS+=	--with-pam
#PLIST_SRC+=		${.CURDIR}/PLIST.pam
#MESSAGE_SRC+=		${.CURDIR}/MESSAGE.pam
#.endif

.if (${OPSYS} == "Darwin") || (${OPSYS} == "SunOS")
.  include "../../security/skey/buildlink2.mk"
CONFIGURE_ARGS+=	--with-skey=${BUILDLINK_PREFIX.skey}
.elif ${OPSYS} == "NetBSD"
# XXX: NetBSD has 4 args (4: sslen) to skeychallenge instead of 3
#CONFIGURE_ARGS+=	--with-skey=/usr
CONFIGURE_ARGS+=	--without-skey
.else
CONFIGURE_ARGS+=	--without-skey
.endif

# XXX: <krb.h>
#.if defined(KERBEROS)
#PKG_USE_KERBEROS=		yes
#CONFIGURE_ARGS+=	--with-kerberos4=/usr
#.endif

LD=	${CC}

# The ssh-askpass program is in ${X11BASE}/bin or ${X11PREFIX}/bin depending
# on if it's part of the X11 distribution, or if it's installed from pkgsrc
# (security/ssh-askpass).
#
.if exists(${X11BASE}/bin/ssh-askpass)
ASKPASS_PROGRAM=	${X11BASE}/bin/ssh-askpass
.else
ASKPASS_PROGRAM=	${X11PREFIX}/bin/ssh-askpass
.endif
CONFIGURE_ENV+=		ASKPASS_PROGRAM=${ASKPASS_PROGRAM}
MAKE_ENV+=		ASKPASS_PROGRAM=${ASKPASS_PROGRAM}

CONFS=			ssh_config sshd_config
SUPPS=			moduli

.if exists(/dev/urandom)
MESSAGE_SRC+=		${.CURDIR}/MESSAGE.urandom
.else
CONFIGURE_ARGS+=	--without-random
CONFS+=			ssh_prng_cmds
PLIST_SRC+=		${.CURDIR}/PLIST.prng
.endif

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		# empty
.for FILE in ${CONFS}
CONF_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor
SUPPORT_FILES=		# empty
.for FILE in ${SUPPS}
SUPPORT_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor
OWN_DIRS=		${OPENSSH_CHROOT}
RCD_SCRIPTS=		sshd

PLIST_SRC+=		${.CURDIR}/PLIST
FILES_SUBST+=		SSH_PID_DIR=${SSH_PID_DIR}
MESSAGE_SUBST+=		EGDIR=${EGDIR}
MESSAGE_SUBST+=		OPENSSH_USER=${OPENSSH_USER}
MESSAGE_SUBST+=		OPENSSH_GROUP=${OPENSSH_GROUP}

.if defined(UPDATE_INTREE_OPENSSH)
.  include "Makefile.intree"
.endif

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}; for file in ${CONFS} ${SUPPS}; do			\
		${INSTALL_DATA} $${file}.out ${EGDIR}/$${file};		\
	done
#.if defined(USE_PAM)
#	${INSTALL_DATA} ${WRKSRC}/contrib/sshd.pam.freebsd ${EGDIR}/sshd.pam
#.endif

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../security/tcp_wrappers/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
