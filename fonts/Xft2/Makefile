# $NetBSD: Makefile,v 1.19 2003/09/27 15:41:53 grant Exp $
#

DISTNAME=	xft-2.1.2
PKGNAME=	Xft2-2.1.2
PKGREVISION=	1
CATEGORIES=	fonts x11
MASTER_SITES=	http://x2.freedesktop.org/Software/fontconfig/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Library for configuring and customizing font access

# This can use 2.0.5 but things which use it (ala pango) require 2.0.9 so make
# sure to keep in step
BUILDLINK_DEPENDS.freetype2=  freetype2>=2.0.9

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
# Uses libtool 1.5 features
#USE_LIBTOOL=		YES
USE_GMAKE=		YES
USE_X11=		YES
USE_GNU_TOOLS+=		awk

PKGCONFIG_OVERRIDE=	${WRKSRC}/xft.pc.in
#LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
MAKE_ENV+=		EGREP=${EGREP}

BUILDLINK_DEPENDS.Xrender=	Xrender>=0.8.2

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../fonts/fontconfig/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../x11/Xrender/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
