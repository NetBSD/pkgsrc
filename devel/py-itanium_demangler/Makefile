#	$NetBSD: Makefile,v 1.1 2020/08/18 20:19:44 riastradh Exp $

DISTNAME=	python-itanium_demangler-1.0
EGG_NAME=	${DISTNAME:C/^python-//g}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=whitequark/}
GITHUB_PROJECT=	python-itanium_demangler
GITHUB_TAG=	a733a9496565631e820e372985ca9551a5077c75

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/whitequark/python-itanium_demangler
COMMENT=	Python parser for the Itanium C++ ABI symbol mangling language
LICENSE=	0-clause-bsd

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
