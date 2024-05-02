# $NetBSD: Makefile,v 1.9 2024/05/02 07:00:59 pho Exp $

DISTNAME=	HsYAML-aeson-0.2.0.1
PKGREVISION=	5
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	JSON to YAML Adapter
LICENSE=	gnu-gpl-v2

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	aeson	\
	base	\
	bytestring	\
	mtl	\
	text	\
	vector

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-HsYAML/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
