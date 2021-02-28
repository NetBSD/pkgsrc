# $NetBSD: Makefile,v 1.3 2021/02/28 13:59:45 mef Exp $

DISTNAME=	hxt-regex-xmlschema-9.2.0.3
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Regular expression library for W3C XML Schema regular expressions
LICENSE=	mit

BUILDLINK_API_DEPENDS.ghc+=	ghc<=8.10
BUILDLINK_API_DEPENDS.ghc+=	ghc>=8.8
.include "../../mk/haskell.mk"
.include "../../textproc/hs-hxt-charproperties/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
