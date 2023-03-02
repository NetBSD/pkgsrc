# $NetBSD: Makefile,v 1.3 2023/03/02 08:15:32 vins Exp $

DISTNAME=	mgdiff
PKGNAME=	${DISTNAME}-1.0.1
PKGREVISION=	1
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://bsdforge.com/projects/textproc/mgdiff/
COMMENT=	Graphical front end to Unix diff
LICENSE=	mit

USE_IMAKE=	yes
USE_TOOLS+=	awk:run ksh:run

REPLACE_KSH=	cvsmgdiff

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	cvsmgdiff rmgdiff README.pkgsrc
SUBST_VARS.prefix=	PREFIX
SUBST_MESSAGE.prefix=	Replacing PREFIX placeholders.

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
SUBST_CLASSES+=		defs
SUBST_STAGE.defs=	post-configure
SUBST_FILES.defs+=	Makefile
SUBST_SED.defs=		-e 's|-D_BSD_SOURCE[[:space:]]*-D_SVID_SOURCE|-D_DEFAULT_SOURCE|g'
SUBST_MESSAGE.defs=	Replacing deprecated preprocessor-defined macros.
.endif

MAKE_FLAGS+=	CCOPTIONS=${CFLAGS:Q}
MAKE_FLAGS+=	LOCAL_LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 libexec/${PKGBASE}
INSTALLATION_DIRS+=	lib/X11/${PKGBASE} lib/X11/app-defaults
INSTALLATION_DIRS+=	share/applications share/doc/${PKGBASE} share/pixmaps

post-extract:
.for f in *mgdiff README*
	${RUN}${CP} ${FILESDIR}/${f} ${WRKSRC}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mgdiff ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mgdiff.man		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mgdiff.1
.for i in cvsmgdiff rmgdiff
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/${i}.1		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor
	${INSTALL_DATA} ${WRKSRC}/Mgdiff.ad		\
		${DESTDIR}${PREFIX}/lib/X11/app-defaults/Mgdiff
	${INSTALL_DATA} ${WRKSRC}/mgdiff.x[bp]m		\
		${DESTDIR}${PREFIX}/lib/X11/${PKGBASE}
	${INSTALL_DATA} ${FILESDIR}/rmgdiff.awk		\
		${DESTDIR}${PREFIX}/libexec/${PKGBASE}

post-install:
	${INSTALL_DATA} ${FILESDIR}/mgdiff-48x48.xpm	\
		${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${FILESDIR}/mgdiff.desktop	\
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/README.pkgsrc		\
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
