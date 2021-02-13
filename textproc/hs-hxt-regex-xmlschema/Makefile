# $NetBSD: Makefile,v 1.2 2021/02/13 08:01:00 mef Exp $

DISTNAME=	hxt-regex-xmlschema-9.2.0.3
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Regular expression library for W3C XML Schema regular expressions
LICENSE=	mit

BUILDLINK_API_DEPENDS.ghc+=	ghc<9.0
.include "../../mk/haskell.mk"
.include "../../textproc/hs-hxt-charproperties/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
