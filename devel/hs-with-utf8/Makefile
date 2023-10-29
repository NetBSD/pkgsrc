# $NetBSD: Makefile,v 1.6 2023/10/29 07:18:44 pho Exp $

DISTNAME=	with-utf8-1.0.2.4
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
