# $NetBSD: Makefile,v 1.13 2002/09/21 23:46:52 jlam Exp $

DISTNAME=		yplot-1.1.0
PKGREVISION=		1
CATEGORIES=		graphics math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=yplot/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://yplot.sourceforge.net/
COMMENT=		Yorick interface to PLplot

DEPENDS+=		yorick-1.4*:../../math/yorick
DEPENDS+=		plplot>=5.0.3:../../graphics/plplot
BUILD_DEPENDS+=		teTeX>=1.0:../../print/teTeX

.if (${MACHINE_ARCH} == "sparc64")
BROKEN=			Compiling hangs, needs attention.
.endif

EVAL_PREFIX+=		PLPLOT_PREFIX=plplot
CONFIGURE_ENV+=		PLPLOT_PREFIX=${PLPLOT_PREFIX}
EVAL_PREFIX+=		YORICK_PREFIX=yorick
CONFIGURE_ENV+=		YORICK_CONTRIB_PREFIX=${YORICK_PREFIX}/lib/yorick/1.4

GNU_CONFIGURE=		yes
MAKEFILE=		Makefile.build

PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_PATCH_SCRIPTS=	parse_documentation.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
