# $NetBSD: Makefile,v 1.80 2002/06/27 10:49:40 itojun Exp $

DISTNAME=		openssh-3.4p1
PKGNAME=		openssh-3.4.0.1
SVR4_PKGNAME=		ossh
CATEGORIES=		security
MASTER_SITES=		ftp://gd.tuwien.ac.at/opsys/OpenBSD/OpenSSH/portable/ \
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

# 0.9.5a can be used, with blowfish support broken.  so require 0.9.6.
USE_OPENSSL_VERSION=	${OPENSSL_VERSION_096}

CRYPTO=			yes

# retain the following line, for IPv6-ready pkgsrc webpage 
BUILD_DEFS+=		USE_INET6
#BUILD_DEFS+=		KERBEROS
BUILD_DEFS+=		PKG_SYSCONFDIR

.include "../../mk/bsd.prefs.mk"

INSTALL_TARGET=		install-nokeys
PLIST_SRC=		# empty
MESSAGE_SRC=		${.CURDIR}/MESSAGE

SSH_PID_DIR=		/var/run	# default directory for PID files
SSH_PID_DIR.SunOS=	/etc		# Solaris doesn't have a /var/run

.if defined(SSH_PID_DIR.${OPSYS})
SSH_PID_DIR=		${SSH_PID_DIR.${OPSYS}}
.endif

PKG_SYSCONFSUBDIR=	ssh

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-pid-dir=${SSH_PID_DIR}
CONFIGURE_ARGS+=	--with-ssl-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-tcp-wrappers=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-privsep-path=/var/chroot/sshd

# XXX: PAM authentication causes memory faults, and I haven't tracked down
# XXX: why yet.  For the moment, disable PAM authentication.
#
#.if defined(USE_PAM)
#.include "../../security/PAM/buildlink.mk"
#CONFIGURE_ARGS+=	--with-pam
#PLIST_SRC+=		${.CURDIR}/PLIST.pam
#MESSAGE_SRC+=		${.CURDIR}/MESSAGE.pam
#.endif

# XXX: we have 4 args (4: sslen) to skeychallenge instead of 3
#.if ${OPSYS} == "NetBSD"
#CONFIGURE_ARGS+=	--with-skey=/usr
#.endif

# XXX: <krb.h>
#.if defined(KERBEROS)
#PKG_USE_KERBEROS=		yes
#CONFIGURE_ARGS+=	--with-kerberos4=/usr
#.endif

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
RCD_SCRIPTS=		sshd

PLIST_SRC+=		${.CURDIR}/PLIST
FILES_SUBST+=		SSH_PID_DIR=${SSH_PID_DIR}
MESSAGE_SUBST+=		EGDIR=${EGDIR}
INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/sshd.sh > ${WRKDIR}/sshd

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}; for file in ${CONFS} ${SUPPS}; do			\
		${INSTALL_DATA} $${file}.out ${EGDIR}/$${file};		\
	done
#.if defined(USE_PAM)
#	${INSTALL_DATA} ${WRKSRC}/contrib/sshd.pam.freebsd ${EGDIR}/sshd.pam
#.endif
	${INSTALL_SCRIPT} ${WRKDIR}/sshd ${PREFIX}/etc/rc.d/sshd
	${MKDIR} /var/chroot/sshd

.include "../../devel/zlib/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../security/tcp_wrappers/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
