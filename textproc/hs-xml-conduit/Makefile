# $NetBSD: Makefile,v 1.9 2023/01/26 17:50:53 pho Exp $

DISTNAME=	xml-conduit-1.9.1.1
PKGREVISION=	7
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Pure-Haskell utilities for dealing with XML with the conduit package
LICENSE=	mit

# Setup.hs mentions Distribution.Extra.Doctest which isn't a part of
# Cabal but is from cabal-doctest. We don't run the doctest anyway, so
# just overwrite it.
post-extract:
	${CP} -f ${FILESDIR}/Setup.hs ${WRKSRC}/Setup.hs

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	resourcet

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
