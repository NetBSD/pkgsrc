# $NetBSD: Makefile,v 1.2 2007/02/01 16:28:14 joerg Exp $

DISTNAME=	xmorph_20060817
PKGNAME=	xmorph-20060817
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmorph/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xmorph.sourceforge.net/home/gourlay/public_html/Xmorph/
COMMENT=	X program for image warping and dissolving

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-gtkmorph=no
USE_LANGUAGES+=	c c++ fortran
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../math/fftw/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
