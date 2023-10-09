# $NetBSD: Makefile,v 1.5 2023/10/09 04:54:35 pho Exp $

DISTNAME=	with-utf8-1.0.2.3
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Get your IO right on the first try
LICENSE=	mpl-2.0

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	text

# lib:with-utf8
.include "../../devel/hs-safe-exceptions/buildlink3.mk"

# exe:utf8-troubleshoot
.include "../../devel/hs-th-env/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
