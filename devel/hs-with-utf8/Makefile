# $NetBSD: Makefile,v 1.10 2025/02/01 10:03:46 pho Exp $

DISTNAME=	with-utf8-1.1.0.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Get your IO right on the first try
LICENSE=	mpl-2.0

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	filepath

# lib:with-utf8
.include "../../devel/hs-safe-exceptions/buildlink3.mk"

# exe:utf8-troubleshoot
.include "../../devel/hs-th-env/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
