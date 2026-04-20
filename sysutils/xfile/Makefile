# $NetBSD: Makefile,v 1.8 2026/04/20 16:06:01 vins Exp $

DISTNAME=	xfile-src-1.1.0
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	sysutils x11
MASTER_SITES=	https://fastestcode.org/dl/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.xz

DISTFILES+=	${DEFAULT_DISTFILES} xfile-addon.tar.xz \
		xfile-slanted-icons.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://fastestcode.org/xfile.html
COMMENT=	File manager for Unix/X11
LICENSE=	mit

MAKE_JOBS_SAFE=	no

USE_TOOLS+=		awk sed sh
USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.prefs.mk"

# See the included README.pkgsrc for optional dependencies.

.if ${X11_TYPE} == "modular"
DEPENDS+=	xterm-[0-9]*:../../x11/xterm
.endif
DEPENDS+=	xfind-[0-9]*:../../x11/xfind

SHAREDIR=	${PREFIX}/share/${PKGBASE}

SUBST_CLASSES+=		pkgsrc
SUBST_STAGE.pkgsrc=	pre-configure
SUBST_FILES.pkgsrc=	mf/Makefile.pkgsrc README.pkgsrc
SUBST_VARS.pkgsrc+=	PKGBASE PREFIX PKGMANDIR SHAREDIR
SUBST_MESSAGE.pkgsrc=	Replacing pkgsrc placeholders

.include "options.mk"

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	SHELL=${SH:Q}
MAKE_FLAGS+=	AWK=${AWK:Q}

post-extract:
	${RUN}${MV} ${WRKDIR}/slanted-icons/*.xpm	\
	${WRKSRC}/src/icons/
	${RUN}${CP} ${FILESDIR}/README.pkgsrc ${WRKSRC}

INSTALLATION_DIRS+=	share/applications

post-install:
	${RUN}${LN} -s ${PREFIX}/bin/xfile			\
		${DESTDIR}${PREFIX}/bin/xfile-open
	${INSTALL_DATA} ${WRKDIR}/xfile-addon/icons/*.xpm	\
		${DESTDIR}${SHAREDIR}/icons
	${INSTALL_DATA} ${WRKDIR}/xfile-addon/types/*.db	\
		${DESTDIR}${SHAREDIR}/types
	${INSTALL_DATA} ${FILESDIR}/xfile.desktop		\
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/README.pkgsrc			\
		${DESTDIR}${PREFIX}/share/doc/xfile

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
