# $NetBSD: Makefile,v 1.7 2004/04/02 20:17:44 salo Exp $
#

DISTNAME=	vsftpd-1.2.1
CATEGORIES=	net
MASTER_SITES=	ftp://vsftpd.beasts.org/users/cevans/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://vsftpd.beasts.org/
COMMENT=	FTP server that aims to be very secure

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES

PKG_SYSCONFSUBDIR=	vsftpd

ALL_TARGET=	vsftpd
RCD_SCRIPTS=	vsftpd

VSFTPD_USER?=	vsftpd
VSFTPD_GROUP?=	vsftpd
PKG_GROUPS=	${VSFTPD_GROUP}
PKG_USERS=	${VSFTPD_USER}:${VSFTPD_GROUP}::vsftpd\\ user

DOCDIR=		${PREFIX}/share/doc/vsftpd
EGDIR=		${PREFIX}/share/examples/vsftpd

CFLAGS=		-DPKG_SYSCONFDIR=\"\\\"${PKG_SYSCONFDIR}\\\"\"

CONF_FILES=	${EGDIR}/vsftpd.conf.default ${PKG_SYSCONFDIR}/vsftpd.conf
MAKE_DIRS=	/var/chroot
OWN_DIRS=	/var/chroot/vsftpd

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
BUILD_DEFS+=	USE_INET6
.endif

post-patch:
	@cd ${WRKSRC} && \
		for f in vsftpd.8 vsftpd.conf.5 vsftpd.conf; do		\
			${MV} $${f} $${f}.orig;				\
			${SED} ${FILES_SUBST_SED} $${f}.orig > $${f};	\
		done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vsftpd ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/vsftpd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/vsftpd.conf.5 ${PREFIX}/man/man5
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/vsftpd.conf ${EGDIR}/vsftpd.conf.default
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} FAQ INSTALL README TUNING ${DOCDIR}

.include "../../security/tcp_wrappers/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
