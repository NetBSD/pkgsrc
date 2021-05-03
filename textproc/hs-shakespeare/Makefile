# $NetBSD: Makefile,v 1.4 2021/05/03 19:01:17 pho Exp $

DISTNAME=	shakespeare-2.0.25
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Toolkit for making compile-time interpolated templates
LICENSE=	mit

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-th-lift/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
