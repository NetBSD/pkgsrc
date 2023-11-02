# $NetBSD: Makefile,v 1.11 2023/11/02 06:37:35 pho Exp $

DISTNAME=	regex-pcre-0.95.0.0
PKGREVISION=	7
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	PCRE Backend for "Text.Regex" (regex-base)
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	bytestring

.include "../../mk/haskell.mk"
.include "../../textproc/hs-regex-base/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
