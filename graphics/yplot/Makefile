# $NetBSD: Makefile,v 1.9 2002/01/19 13:40:54 drochner Exp $

DISTNAME=		yplot-1.1.0
CATEGORIES=		graphics math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=yplot/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://yplot.sourceforge.net/
COMMENT=		Yorick interface to PLplot

DEPENDS+=		yorick-1.4*:../../math/yorick
DEPENDS+=		plplot>=5.0.3:../../graphics/plplot
BUILD_DEPENDS+=		teTeX>=1.0:../../print/teTeX

EVAL_PREFIX+=		PLPLOT_PREFIX=plplot
CONFIGURE_ENV+=		PLPLOT_PREFIX=${PLPLOT_PREFIX}
EVAL_PREFIX+=		YORICK_PREFIX=yorick
CONFIGURE_ENV+=		YORICK_CONTRIB_PREFIX=${YORICK_PREFIX}/lib/yorick/1.4

GNU_CONFIGURE=		yes
MAKEFILE=		Makefile.build

PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_PATCH_SCRIPTS=	parse_documentation.py

.include "../../lang/python/application.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
