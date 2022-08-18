# $NetBSD: Makefile,v 1.8 2022/08/18 18:26:47 wiz Exp $

DISTNAME=	base-compat-batteries-0.12.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Base library compatibility without cpp
LICENSE=	mit

BUILDLINK_API_DEPENDS.hs-base-compat+=	hs-base-compat>=0.12.2
.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
