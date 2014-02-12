# $NetBSD: Makefile,v 1.40 2014/02/12 23:18:27 tron Exp $
#

DISTNAME=	vsftpd-2.3.4
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://security.appspot.com/downloads/ \
		${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vsftpd.beasts.org/
COMMENT=	FTP server that aims to be very secure
LICENSE=	gnu-gpl-v2

PKG_SYSCONFSUBDIR=	vsftpd

USE_FEATURES+=		inet6

BUILD_TARGET=	vsftpd
RCD_SCRIPTS=	vsftpd

BUILD_DEFS+=	VARBASE

DOCDIR=		${PREFIX}/share/doc/vsftpd
EGDIR=		${PREFIX}/share/examples/vsftpd

CONF_FILES=	${EGDIR}/vsftpd.conf.default ${PKG_SYSCONFDIR}/vsftpd.conf
MAKE_DIRS=	${VARBASE}/chroot
OWN_DIRS=	${VARBASE}/chroot/vsftpd

INSTALLATION_DIRS=	libexec ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 \
			${EGDIR} ${DOCDIR}/SECURITY

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	vsftpd.8 vsftpd.conf.5 vsftpd.conf
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_STAGE.paths=	post-patch

MAKE_ENV+=		LIBS=${LIBS:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && ${OS_VERSION} == "5.11"
SUBST_CLASSES+=		dirfd
SUBST_STAGE.dirfd=	pre-build
SUBST_FILES.dirfd=	port/solaris_bogons.h
SUBST_SED.dirfd=	-e '/dirfd_extras/d'
.endif

VSFTPD_USER?=	vsftpd
VSFTPD_GROUP?=	vsftpd
PKG_GROUPS=	${VSFTPD_GROUP}
PKG_USERS=	${VSFTPD_USER}:${VSFTPD_GROUP}

PKG_GROUPS_VARS+=	VSFTPD_GROUP
PKG_USERS_VARS+=	VSFTPD_USER

CFLAGS+=	-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""
LIBS.SunOS=	-lsocket -lnsl -lrt -lsendfile -lresolv

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
