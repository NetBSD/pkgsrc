# $NetBSD: Makefile,v 1.2 2020/04/03 07:28:12 wiz Exp $

DISTNAME=	hashtables-1.2.3.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=hashtables-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gregorycollins/hashtables
COMMENT=	Mutable hash tables in the ST monad
LICENSE=	modified-bsd

DEPENDS+=	hs-hashable-[0-9]*:../../devel/hs-hashable
DEPENDS+=	hs-primitive-[0-9]*:../../devel/hs-primitive
DEPENDS+=	hs-vector-[0-9]*:../../devel/hs-vector

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
