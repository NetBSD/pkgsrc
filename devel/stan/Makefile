# $NetBSD: Makefile,v 1.3 2025/01/31 11:07:03 pho Exp $

DISTNAME=	stan-0.2.0.0
PKGNAME=	${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Haskell STatic ANalyser
LICENSE=	mpl-2.0

# lib:stan
.include "../../converters/hs-base64/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-clay/buildlink3.mk"
.include "../../devel/hs-colourista/buildlink3.mk"
.include "../../security/hs-cryptohash-sha1/buildlink3.mk"
.include "../../sysutils/hs-dir-traverse/buildlink3.mk"
.include "../../devel/hs-extensions/buildlink3.mk"
.include "../../devel/hs-gitrev/buildlink3.mk"
.include "../../converters/hs-microaeson/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-pretty-simple/buildlink3.mk"
.include "../../devel/hs-relude/buildlink3.mk"
.include "../../devel/hs-slist/buildlink3.mk"
.include "../../textproc/hs-tomland/buildlink3.mk"
.include "../../devel/hs-trial/buildlink3.mk"
.include "../../devel/hs-trial-optparse-applicative/buildlink3.mk"
.include "../../textproc/hs-trial-tomland/buildlink3.mk"

# lib:target
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"

# exe:stan
.include "../../devel/hs-optparse-applicative/application.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
