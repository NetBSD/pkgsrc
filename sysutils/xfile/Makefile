# $NetBSD: Makefile,v 1.1 2025/01/05 21:38:21 vins Exp $

DISTNAME=	xfile-src-1.0-beta
PKGNAME=	${DISTNAME:S/-src//:S/-beta/beta/}
CATEGORIES=	sysutils x11
MASTER_SITES=	https://fastestcode.org/dl/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.xz
DISTFILES+=	${DEFAULT_DISTFILES} xfile-xdgsvc-src.tar.xz	\
		xfile-slanted-icons.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://fastestcode.org/xfile.html
COMMENT=	File manager for Unix/X11
LICENSE=	mit

MAKE_JOBS_SAFE=	no

USE_TOOLS+=		awk sed sh
USE_BSD_MAKEFILE=	yes

SHAREDIR=	${PREFIX}/share/${PKGBASE}

SUBST_CLASSES+=		pkgsrc
SUBST_STAGE.pkgsrc=	pre-configure
SUBST_FILES.pkgsrc=	mf/Makefile.pkgsrc src/mkicons.sh src/xfile.service
SUBST_VARS.pkgsrc+=	PKGBASE PREFIX PKGMANDIR SED SHAREDIR
SUBST_MESSAGE.pkgsrc=	Replacing pkgsrc placeholders

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	SHELL=${SH:Q}
MAKE_FLAGS+=	AWK=${AWK:Q}

WRKSRC=	${WRKDIR}/xfile-beta

post-extract:
	${RUN}${MV} ${WRKDIR}/slanted-icons/*.xpm	\
		${WRKSRC}/addon/icons/
.for f in xfile-xdg.c xfile.service
	${RUN}${MV} ${WRKDIR}/xfile-xdgsvc/${f} ${WRKSRC}/src
.endfor

INSTALLATION_DIRS+=	share/applications

post-install:
	${RUN}${LN} -s ${DESTDIR}${PREFIX}/bin/xfile	\
		${DESTDIR}${PREFIX}/bin/xfile-open
	${INSTALL_DATA} ${WRKSRC}/addon/icons/*.xpm	\
		${DESTDIR}${SHAREDIR}/icons
	${INSTALL_DATA} ${WRKSRC}/addon/types/*.db	\
		${DESTDIR}${SHAREDIR}/types
	${INSTALL_DATA} ${FILESDIR}/xfile.desktop  	\
		${DESTDIR}${PREFIX}/share/applications

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
