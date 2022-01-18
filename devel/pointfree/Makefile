# $NetBSD: Makefile,v 1.4 2022/01/18 02:48:16 pho Exp $
#

DISTNAME=	pointfree-1.1.1.7
PKGNAME=	${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Convert Haskell expressions to pointfree form
LICENSE=	mit

# "pointfree.cabal" declares an empty library (exposing no symbols at
# all), and the executable doesn't depend on the library either. This
# is not only pointless, but also makes Cabal do a weird thing
# possibly due to a bug: it embeds an rpath to the *build directory*
# which serves absolutely no purpose. Disable the library as a
# workaround.
SUBST_CLASSES+=	1
SUBST_STAGE.1=	post-extract
SUBST_FILES.1=	pointfree.cabal
SUBST_SED.1=	-e "s|Library|Library+  buildable: False|"

SUBST_CLASSES+=		2
SUBST_STAGE.2=		pre-configure
SUBST_FILES.2=		pointfree.cabal
SUBST_FILTER_CMD.2=	${TR} '+' \\n

.include "../../devel/hs-haskell-src-exts/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
