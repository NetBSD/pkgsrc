# $NetBSD: Makefile,v 1.8 2022/01/10 08:44:17 wiz Exp $

VERSION=	1.26.0
DISTNAME=	PyPDF2-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
PKGREVISION=	2
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_GITHUB:=mstamy2/}
GITHUB_PROJECT=	PyPDF2
GITHUB_TAG=	${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mstamy2.github.io/PyPDF2/
COMMENT=	PDF library for python
LICENSE=	modified-bsd

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
