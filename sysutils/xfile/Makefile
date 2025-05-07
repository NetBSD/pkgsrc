# $NetBSD: Makefile,v 1.3 2025/05/07 15:56:43 vins Exp $

DISTNAME=	xfile-20250430
PKGREVISION=	1
CATEGORIES=	sysutils x11
#MASTER_SITES=	https://fastestcode.org/dl/
MASTER_SITES=	${MASTER_SITE_GITHUB:=alx210/}
DIST_SUBDIR=	${PKGNAME_NOREV}
GITHUB_TAG=	ffdae16e124727f85b3ad3226d619a8d0ab4abe9

DISTFILES+=	${DEFAULT_DISTFILES} xfile-slanted-icons.tar.xz
SITES.xfile-slanted-icons.tar.xz= https://fastestcode.org/dl/

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
SUBST_FILES.pkgsrc=	mf/Makefile.pkgsrc src/mkicons.sh
SUBST_VARS.pkgsrc+=	PKGBASE PREFIX PKGMANDIR SED SHAREDIR
SUBST_MESSAGE.pkgsrc=	Replacing pkgsrc placeholders

.include "options.mk"

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	SHELL=${SH:Q}
MAKE_FLAGS+=	AWK=${AWK:Q}

#WRKSRC=	${WRKDIR}/xfile-beta

post-extract:
	${RUN}${MV} ${WRKDIR}/slanted-icons/*.xpm	\
	${WRKSRC}/addon/icons/

INSTALLATION_DIRS+=	share/applications

post-install:
	${RUN}${LN} -s ${PREFIX}/bin/xfile ${DESTDIR}${PREFIX}/bin/xfile-open
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
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
