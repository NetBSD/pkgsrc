# $NetBSD: Makefile,v 1.25 2004/02/15 15:47:42 recht Exp $

DISTNAME=	TeXmacs-1.0.3.3-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.texmacs.org/pub/TeXmacs/targz/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.texmacs.org/
COMMENT=	GNU TeXmacs (free scientific text editor)

DEPENDS+=	teTeX>=1.0:../../print/teTeX

ALL_TARGET=	TEXMACS

USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++
USE_X11=	yes
USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	PKG_CXXFLAGS="${PKG_CXXFLAGS}"
CONFIGURE_ENV+=	PKG_LDFLAGS="${LDFLAGS}"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
