# $NetBSD: Makefile,v 1.1 2020/03/30 16:47:25 riastradh Exp $

DISTNAME=	lucid-2.9.12
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=lucid-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chrisdone/lucid
COMMENT=	Clear to write, read and edit DSL for HTML
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../devel/hs-mmorph/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
