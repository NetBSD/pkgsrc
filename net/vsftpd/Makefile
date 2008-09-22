# $NetBSD: Makefile,v 1.29 2008/09/22 11:02:21 abs Exp $
#

DISTNAME=	vsftpd-2.0.7
CATEGORIES=	net
MASTER_SITES=	ftp://vsftpd.beasts.org/users/cevans/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vsftpd.beasts.org/
COMMENT=	FTP server that aims to be very secure

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_SYSCONFSUBDIR=	vsftpd

BUILD_TARGET=	vsftpd
RCD_SCRIPTS=	vsftpd

PKG_GROUPS_VARS+=	VSFTPD_GROUP
PKG_USERS_VARS+=	VSFTPD_USER

VSFTPD_USER?=	vsftpd
VSFTPD_GROUP?=	vsftpd
PKG_GROUPS=	${VSFTPD_GROUP}
PKG_USERS=	${VSFTPD_USER}:${VSFTPD_GROUP}

DOCDIR=		${PREFIX}/share/doc/vsftpd
EGDIR=		${PREFIX}/share/examples/vsftpd

CFLAGS+=	-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

CONF_FILES=	${EGDIR}/vsftpd.conf.default ${PKG_SYSCONFDIR}/vsftpd.conf
MAKE_DIRS=	${VARBASE}/chroot
OWN_DIRS=	${VARBASE}/chroot/vsftpd

INSTALLATION_DIRS=	libexec ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 \
			${EGDIR} ${DOCDIR}/SECURITY

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	vsftpd.8 vsftpd.conf.5 vsftpd.conf
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_STAGE.paths=	post-patch

MAKE_ENV+=		LIBS=${LIBS:M*:Q}

.include "../../mk/bsd.prefs.mk"

LIBS.SunOS=	-lsocket -lnsl -lrt -lsendfile

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vsftpd ${DESTDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/vsftpd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/vsftpd.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/vsftpd.conf ${DESTDIR}${EGDIR}/vsftpd.conf.default
	cd ${WRKSRC} && ${INSTALL_DATA} FAQ INSTALL README README.ssl \
		TUNING ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/SECURITY/* ${DESTDIR}${DOCDIR}/SECURITY

.include "../../mk/bsd.pkg.mk"
