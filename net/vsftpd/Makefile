# $NetBSD: Makefile,v 1.20 2006/01/30 18:07:06 wiz Exp $
#

DISTNAME=	vsftpd-2.0.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://vsftpd.beasts.org/users/cevans/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://vsftpd.beasts.org/
COMMENT=	FTP server that aims to be very secure

PKG_SYSCONFSUBDIR=	vsftpd

BUILD_TARGET=	vsftpd
RCD_SCRIPTS=	vsftpd

VSFTPD_USER?=	vsftpd
VSFTPD_GROUP?=	vsftpd
PKG_GROUPS=	${VSFTPD_GROUP}
PKG_USERS=	${VSFTPD_USER}:${VSFTPD_GROUP}::vsftpd\ user

DOCDIR=		${PREFIX}/share/doc/vsftpd
EGDIR=		${PREFIX}/share/examples/vsftpd

CFLAGS+=	-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

CONF_FILES=	${EGDIR}/vsftpd.conf.default ${PKG_SYSCONFDIR}/vsftpd.conf
MAKE_DIRS=	${VARBASE}/chroot
OWN_DIRS=	${VARBASE}/chroot/vsftpd

INSTALLATION_DIRS=	libexec man/man5 man/man8

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	vsftpd.8 vsftpd.conf.5 vsftpd.conf
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_STAGE.paths=	post-patch

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vsftpd ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/vsftpd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/vsftpd.conf.5 ${PREFIX}/man/man5
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/vsftpd.conf ${EGDIR}/vsftpd.conf.default
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/SECURITY
	cd ${WRKSRC} && ${INSTALL_DATA} FAQ INSTALL README README.ssl \
		TUNING ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/SECURITY/* ${DOCDIR}/SECURITY

.include "../../mk/bsd.pkg.mk"
