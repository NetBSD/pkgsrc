# $NetBSD: Makefile,v 1.23 2004/01/22 08:30:30 grant Exp $

DISTNAME=	TeXmacs-1.0.3.1-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.texmacs.org/pub/TeXmacs/targz/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.texmacs.org/
COMMENT=	GNU TeXmacs (free scientific text editor)

DEPENDS+=	teTeX>=1.0:../../print/teTeX

ALL_TARGET=	TEXMACS

USE_BUILDLINK2=	yes
USE_GNU_TOOLS+=	make
USE_X11=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	PKG_CXXFLAGS="${PKG_CXXFLAGS}"
CONFIGURE_ENV+=	PKG_LDFLAGS="${LDFLAGS}"

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../lang/guile/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
