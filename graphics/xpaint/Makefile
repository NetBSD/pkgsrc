# $NetBSD: Makefile,v 1.51 2005/09/06 14:53:36 adam Exp $

DISTNAME=       xpaint-2.7.8
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sf-xpaint/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://sf-xpaint.sourceforge.net/
COMMENT=	Simple paint program

USE_IMAKE=      	yes
USE_TOOLS+=		gmake
MAKE_ENV+=		XMKMF="${XMKMF}"
BUILD_TARGET=		xaw3dg

SUBST_CLASSES=		foo
SUBST_STAGE.foo=	pre-configure
SUBST_FILES.foo=	Local.config configure
SUBST_SED.foo=		-e "s|@LOCALBASE@|${LOCALBASE}|g" \
			-e "s|@PREFIX@|${PREFIX}|g" \
			-e "s|@XAWDIR@|${BUILDLINK_PREFIX.Xaw3d}|g" \
			-e "s|@XPMDIR@|${BUILDLINK_PREFIX.xpm}|g"

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/Xaw3d/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
