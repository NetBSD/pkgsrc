# $NetBSD: Makefile,v 1.7 2022/02/26 03:58:29 pho Exp $

DISTNAME=	regex-pcre-0.95.0.0
PKGREVISION=	4
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	PCRE Backend for "Text.Regex" (regex-base)
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config

.include "../../mk/haskell.mk"
.include "../../textproc/hs-regex-base/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
