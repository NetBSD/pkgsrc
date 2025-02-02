# $NetBSD: Makefile,v 1.16 2025/02/02 13:05:56 pho Exp $

DISTNAME=	regex-tdfa-1.3.2.2
PKGREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Pure Haskell Tagged DFA Backend for "Text.Regex" (regex-base)
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	containers	\
	text

.include "../../mk/haskell.mk"
.include "../../textproc/hs-regex-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
