# $NetBSD: Makefile,v 1.6 2025/02/02 13:05:59 pho Exp $

DISTNAME=	toml-parser-2.0.1.0
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	TOML 1.0.0 parser
LICENSE=	isc

USE_TOOLS+=	alex happy

.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
