# $NetBSD: Makefile,v 1.1 2020/03/30 16:49:19 riastradh Exp $

DISTNAME=	cassava-0.5.2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=cassava-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hvr/cassava
COMMENT=	CSV parsing and encoding library
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../devel/hs-Only/buildlink3.mk"
.include "../../devel/hs-bytestring-builder/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../textproc/hs-text-short/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
