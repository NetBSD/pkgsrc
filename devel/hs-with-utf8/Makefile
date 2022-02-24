# $NetBSD: Makefile,v 1.1 2022/02/24 01:26:50 pho Exp $

DISTNAME=	with-utf8-1.0.2.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Get your IO right on the first try
LICENSE=	mpl-2.0

# lib:with-utf8
.include "../../devel/hs-safe-exceptions/buildlink3.mk"

# exe:utf8-troubleshoot
.include "../../devel/hs-th-env/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
