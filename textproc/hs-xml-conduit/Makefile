# $NetBSD: Makefile,v 1.14 2024/05/09 01:32:49 pho Exp $

DISTNAME=	xml-conduit-1.9.1.3
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Pure-Haskell utilities for dealing with XML with the conduit package
LICENSE=	mit

# Setup.hs mentions Distribution.Extra.Doctest which isn't a part of
# Cabal but is from cabal-doctest. We don't run the doctest anyway, so
# just remove it.
post-extract:
	${RM} -f ${WRKSRC}/Setup.hs

# We also need to convince mk/haskell.mk that the package doesn't have any
# special build hooks.
SUBST_CLASSES+=		cabal
SUBST_STAGE.cabal=	post-extract
SUBST_FILES.cabal=	xml-conduit.cabal
SUBST_SED.cabal=	-e '/^build-type:/s/Custom/Simple/'

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-extra/buildlink3.mk"
.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../textproc/hs-xml-types/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
