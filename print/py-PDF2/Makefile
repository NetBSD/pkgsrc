# $NetBSD: Makefile,v 1.6 2019/07/29 20:40:19 joerg Exp $

VERSION=	1.26.0
DISTNAME=	PyPDF2-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
PKGREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_GITHUB:=mstamy2/}
GITHUB_PROJECT=	PyPDF2
GITHUB_TAG=	${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mstamy2.github.io/PyPDF2/
COMMENT=	PDF library for python
LICENSE=	modified-bsd

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
