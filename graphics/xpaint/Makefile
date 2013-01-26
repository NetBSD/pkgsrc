# $NetBSD: Makefile,v 1.72 2013/01/26 21:38:02 adam Exp $

DISTNAME=	xpaint-2.7.8.1
PKGREVISION=	9
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sf-xpaint/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://sf-xpaint.sourceforge.net/
COMMENT=	Simple paint program

USE_IMAKE=	yes
USE_TOOLS+=		gmake
MAKE_ENV+=		XMKMF=${XMKMF:Q}
MAKE_JOBS_SAFE=		NO

SUBST_CLASSES+=		foo
SUBST_STAGE.foo=	pre-configure
SUBST_FILES.foo=	Local.config configure
SUBST_SED.foo=		-e "s|@LOCALBASE@|${LOCALBASE}|g" \
			-e "s|@PREFIX@|${PREFIX}|g" \
			-e "s|@XAWDIR@|${BUILDLINK_PREFIX.Xaw3d}|g" \
			-e "s|@XPMDIR@|${BUILDLINK_PREFIX.libXpm}|g"

INSTALLATION_DIRS+=	bin lib/X11/app-defaults ${PKGMANDIR}/cat1
INSTALLATION_DIRS+=	share/xpaint
INSTALLATION_DIRS+=	share/xpaint/include
INSTALLATION_DIRS+=	share/xpaint/c_scripts
INSTALLATION_DIRS+=	share/xpaint/c_scripts/3d_surfaces
INSTALLATION_DIRS+=	share/xpaint/c_scripts/filters
INSTALLATION_DIRS+=	share/xpaint/c_scripts/images
INSTALLATION_DIRS+=	share/xpaint/c_scripts/layers
INSTALLATION_DIRS+=	share/xpaint/c_scripts/procedures
INSTALLATION_DIRS+=	share/xpaint/c_scripts/3d_curves
INSTALLATION_DIRS+=	share/xpaint/help
INSTALLATION_DIRS+=	share/xpaint/messages

pre-configure:
	cd ${WRKSRC} && ./configure xaw3dg

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/Xaw3d/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
