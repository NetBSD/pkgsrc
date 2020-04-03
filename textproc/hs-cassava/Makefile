# $NetBSD: Makefile,v 1.2 2020/04/03 07:40:44 wiz Exp $

DISTNAME=	cassava-0.5.2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=cassava-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hvr/cassava
COMMENT=	CSV parsing and encoding library
LICENSE=	modified-bsd

DEPENDS+=	hs-attoparsec-[0-9]*:../../textproc/hs-attoparsec
DEPENDS+=	hs-unordered-containers-[0-9]*:../../devel/hs-unordered-containers
DEPENDS+=	hs-vector-[0-9]*:../../devel/hs-vector

USE_LANGUAGES=	# none

.include "../../devel/hs-Only/buildlink3.mk"
.include "../../devel/hs-bytestring-builder/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../textproc/hs-text-short/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
