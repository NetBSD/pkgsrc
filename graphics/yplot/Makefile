# $NetBSD: Makefile,v 1.21 2004/10/03 00:14:59 tv Exp $

DISTNAME=		yplot-1.1.2
PKGREVISION=		2
CATEGORIES=		graphics math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=yplot/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://yplot.sourceforge.net/
COMMENT=		Yorick interface to PLplot

BUILD_DEPENDS+=		teTeX>=1.0:../../print/teTeX

.if (${MACHINE_ARCH} == "sparc64")
BROKEN=			Compiling hangs, needs attention.
.endif

USE_BUILDLINK3=		yes
CONFIGURE_ENV+=		PLPLOT_PREFIX=${BUILDLINK_PREFIX.plplot}
EVAL_PREFIX+=		YORICK_PREFIX=yorick
CONFIGURE_ENV+=		YORICK_HOME=${YORICK_PREFIX}
CONFIGURE_ENV+=		YORICK_SITE=${YORICK_PREFIX}/share/yorick
USE_X11=		yes

BUILDLINK_DEPMETHOD.yorick=	full

GNU_CONFIGURE=		yes
MAKEFILE=		Makefile.build

PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_PATCH_SCRIPTS=	parse_documentation.py

.include "../../graphics/plplot/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../math/yorick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
