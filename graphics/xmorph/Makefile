# $NetBSD: Makefile,v 1.14 2020/01/18 23:32:39 rillig Exp $

DISTNAME=	xmorph_20060817
PKGNAME=	xmorph-20060817
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmorph/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xmorph.sourceforge.net/home/gourlay/public_html/Xmorph/
COMMENT=	X program for image warping and dissolving

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtkmorph=no
INFO_FILES=		yes
USE_LANGUAGES=		c c++ fortran77
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

LDFLAGS+=	${COMPILER_RPATH_FLAG}${X11BASE}/lib -L${X11BASE}/lib

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
