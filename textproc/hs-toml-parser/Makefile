# $NetBSD: Makefile,v 1.1 2023/10/27 10:22:19 pho Exp $

DISTNAME=	toml-parser-1.3.0.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	TOML 1.0.0 parser
LICENSE=	isc

USE_TOOLS+=	alex happy

.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
