# $NetBSD: Makefile,v 1.12 2018/07/03 05:03:32 adam Exp $

DISTVERS=	2.2.5
GITREF=		b666238
DISTNAME=	python-openid-${DISTVERS}
PKGNAME=	${PYPKGPREFIX}-openid-${DISTVERS}
CATEGORIES=	security python
MASTER_SITES=	http://github.com/openid/python-openid/tarball/${DISTVERS}/
WRKSRC=		${WRKDIR}/openid-python-openid-${GITREF}

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://www.openidenabled.com/openid/libraries/python/
COMMENT=	Python module for OpenID
LICENSE=	apache-2.0

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
