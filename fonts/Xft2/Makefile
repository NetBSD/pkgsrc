# $NetBSD: Makefile,v 1.16 2003/09/19 15:46:51 markd Exp $
#

DISTNAME=	xft-2.1.2
PKGNAME=	Xft2-2.1.2
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

#LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
MAKE_ENV+=		EGREP=${EGREP}

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../fonts/fontconfig/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../x11/Xrender/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
