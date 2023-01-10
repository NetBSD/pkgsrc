# $NetBSD: Makefile,v 1.52 2023/01/10 20:36:33 otis Exp $

DISTNAME=	vsftpd-3.0.5
CATEGORIES=	net
MASTER_SITES=	https://security.appspot.com/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://security.appspot.com/vsftpd.html
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
SUBST_VARS.paths+=	PKG_SYSCONFDIR VARBASE
SUBST_STAGE.paths=	pre-configure

MAKE_ENV+=		LIBS=${LIBS:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && ${OS_VERSION} == "5.11"
SUBST_CLASSES+=			dirfd
SUBST_STAGE.dirfd=		pre-build
SUBST_FILES.dirfd=		port/solaris_bogons.h
SUBST_SED.dirfd=		-e '/dirfd_extras/d'
.endif
.if !empty(PKGSRC_COMPILER:Mclang)
SUBST_CLASSES+=			idirafter
SUBST_MESSAGE.idirafter=	Fix buggy -idirafter for clang
SUBST_STAGE.idirafter=		pre-build
SUBST_FILES.idirafter=		Makefile
SUBST_SED.idirafter=		-e 's,-idirafter ,-I,'
.endif

VSFTPD_USER?=	vsftpd
VSFTPD_GROUP?=	vsftpd
PKG_GROUPS=	${VSFTPD_GROUP}
PKG_USERS=	${VSFTPD_USER}:${VSFTPD_GROUP}

PKG_GROUPS_VARS+=	VSFTPD_GROUP
PKG_USERS_VARS+=	VSFTPD_USER

CFLAGS+=	-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\"" -DVARBASE="\"${VARBASE}\""
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
