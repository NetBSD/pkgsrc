# $NetBSD: Makefile,v 1.13 2026/09/28 22:32:31 gdt Exp $

# https://github.com/suds-community/suds/archive/refs/tags/v1.2.0.tar.gz
# also
# https://github.com/suds-community/suds/archive/v1.2.0.tar.gz
DISTNAME=	suds-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GITHUB:=suds-community/}
GITHUB_PROJECT=	suds
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/suds-community/suds
COMMENT=	Lightweight SOAP client (community fork)
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.1:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
