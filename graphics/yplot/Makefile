# $NetBSD: Makefile,v 1.17 2003/07/17 21:43:22 grant Exp $

DISTNAME=		yplot-1.1.2
CATEGORIES=		graphics math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=yplot/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://yplot.sourceforge.net/
COMMENT=		Yorick interface to PLplot

DEPENDS+=		yorick-1.5*:../../math/yorick
DEPENDS+=		plplot>=5.0.3:../../graphics/plplot
BUILD_DEPENDS+=		teTeX>=1.0:../../print/teTeX

.if (${MACHINE_ARCH} == "sparc64")
BROKEN=			Compiling hangs, needs attention.
.endif

CONFIGURE_ENV+=		PLPLOT_PREFIX=${BUILDLINK_PREFIX.plplot}
EVAL_PREFIX+=		YORICK_PREFIX=yorick
CONFIGURE_ENV+=		YORICK_HOME=${YORICK_PREFIX}
CONFIGURE_ENV+=		YORICK_SITE=${YORICK_PREFIX}/share/yorick

GNU_CONFIGURE=		yes
MAKEFILE=		Makefile.build

PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_PATCH_SCRIPTS=	parse_documentation.py

.include "../../graphics/plplot/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
