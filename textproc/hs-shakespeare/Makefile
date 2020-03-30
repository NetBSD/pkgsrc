# $NetBSD: Makefile,v 1.1 2020/03/30 16:48:01 riastradh Exp $

DISTNAME=	shakespeare-2.0.24
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=shakespeare-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.yesodweb.com/book/shakespearean-templates
COMMENT=	Toolkit for making compile-time interpolated templates
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../mk/haskell.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
