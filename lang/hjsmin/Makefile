# $NetBSD: Makefile,v 1.5 2025/03/05 03:39:38 pho Exp $

DISTNAME=	hjsmin-0.2.1
PKGNAME=	${DISTNAME}
PKGREVISION=	4
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Haskell implementation of a javascript minifier
LICENSE=	modified-bsd

# lib:hjsmin
.include "../../lang/hs-language-javascript/buildlink3.mk"

# exe:hjsmin
.include "../../devel/hs-optparse-applicative/application.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
