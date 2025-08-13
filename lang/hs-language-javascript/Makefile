# $NetBSD: Makefile,v 1.10 2025/08/13 11:07:11 pho Exp $

DISTNAME=	language-javascript-0.7.1.0
PKGREVISION=	8
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parser for JavaScript
LICENSE=	modified-bsd

USE_TOOLS+=	alex happy

.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
