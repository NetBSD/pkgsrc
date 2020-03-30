# $NetBSD: Makefile,v 1.1 2020/03/30 16:49:55 riastradh Exp $

DISTNAME=	cassava-megaparsec-2.0.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=cassava-megaparsec-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stackbuilders/cassava-megaparsec
COMMENT=	Megaparsec parser of CSV files that plays nicely with Cassava
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../mk/haskell.mk"
.include "../../textproc/hs-cassava/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
