# $NetBSD: Makefile,v 1.1 2016/11/21 11:45:32 fhajny Exp $

DISTNAME=	requests-file-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=dashea/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dashea/requests-file/
COMMENT=	Transport adapter for file:// URLs with the requests python lib
LICENSE=	apache-2.0

GITHUB_PROJECT=	requests-file
GITHUB_TAG=	${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-requests>=1.0.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
