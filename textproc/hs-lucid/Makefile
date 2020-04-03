# $NetBSD: Makefile,v 1.2 2020/04/03 07:22:04 wiz Exp $

DISTNAME=	lucid-2.9.12
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=lucid-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chrisdone/lucid
COMMENT=	Clear to write, read and edit DSL for HTML
LICENSE=	modified-bsd

DEPENDS+=	hs-blaze-builder-[0-9]*:../../devel/hs-blaze-builder
DEPENDS+=	hs-unordered-containers-[0-9]*:../../devel/hs-unordered-containers

USE_LANGUAGES=	# none

.include "../../devel/hs-mmorph/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
