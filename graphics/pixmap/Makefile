# $NetBSD: Makefile,v 1.37 2024/12/04 10:40:37 nros Exp $

DISTNAME=		pixmap2.6
PKGNAME=		pixmap-2.6.4
PKGREVISION=		9
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/pixmap/}
LICENSE=		x11

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		pixmap_2.6.patch1.gz \
			pixmap_2.6.patch2.gz \
			pixmap_2.6.patch3.gz \
			pixmap_2.6.patch4.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Pixmap editor based on XPM library

WRKSRC=			${WRKDIR}/pixmap
USE_IMAKE=		YES

MAKE_ENV+=		LOCAL_LDFLAGS=${LDFLAGS:Q}
MAKE_ENV+=		MOTIFBASE=${MOTIFBASE}

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
DEPENDS+=	rgb>=1.0.1:../../x11/rgb
RGBTXT=		${PREFIX}/share/X11/rgb.txt
.else
RGBTXT=		${X11BASE}/lib/X11/rgb.txt
.endif

SUBST_CLASSES+=		rgb
SUBST_STAGE.rgb=	pre-configure
SUBST_FILES.rgb=	Imakefile
SUBST_VARS.rgb=		RGBTXT

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

post-extract:
	rm -rf ${WRKSRC}/X11
	${CP} ${FILESDIR}/rgb.h ${WRKSRC}
	${CP} ${FILESDIR}/rgb.c ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${FILESDIR}/COPYRIGHT.rgb \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
