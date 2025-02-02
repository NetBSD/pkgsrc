# $NetBSD: Makefile,v 1.14 2025/02/02 13:05:56 pho Exp $

DISTNAME=	regex-pcre-0.95.0.0
PKGREVISION=	9
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	PCRE Backend for "Text.Regex" (regex-base)
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	bytestring	\
	containers

.include "../../textproc/hs-regex-base/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
