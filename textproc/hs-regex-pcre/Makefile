# $NetBSD: Makefile,v 1.16 2025/08/13 11:07:34 pho Exp $

DISTNAME=	regex-pcre-0.95.0.0
PKGREVISION=	11
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
