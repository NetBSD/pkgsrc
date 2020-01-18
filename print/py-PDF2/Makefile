# $NetBSD: Makefile,v 1.7 2020/01/18 23:33:30 rillig Exp $

VERSION=	1.26.0
DISTNAME=	PyPDF2-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
PKGREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_GITHUB:=mstamy2/}
GITHUB_PROJECT=	PyPDF2
GITHUB_TAG=	${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mstamy2.github.io/PyPDF2/
COMMENT=	PDF library for python
LICENSE=	modified-bsd

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
