# $NetBSD: Makefile,v 1.3 2021/05/03 19:01:17 pho Exp $

DISTNAME=	regex-pcre-0.95.0.0
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	PCRE Backend for "Text.Regex" (regex-base)
LICENSE=	modified-bsd

.include "../../mk/haskell.mk"
.include "../../textproc/hs-regex-base/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
