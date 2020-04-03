# $NetBSD: Makefile,v 1.2 2020/04/03 07:32:32 wiz Exp $

DISTNAME=	text-short-0.1.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=text-short-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hackage.haskell.org/package/text-short
COMMENT=	Memory-efficient representation of Unicode text strings
LICENSE=	modified-bsd

DEPENDS+=	hs-hashable-[0-9]*:../../devel/hs-hashable

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
