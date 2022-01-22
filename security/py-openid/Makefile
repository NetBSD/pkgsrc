# $NetBSD: Makefile,v 1.16 2022/01/22 14:25:43 wiz Exp $

DISTVERS=	2.2.5
GITREF=		b666238
DISTNAME=	python-openid-${DISTVERS}
PKGNAME=	${PYPKGPREFIX}-openid-${DISTVERS}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	http://github.com/openid/python-openid/tarball/${DISTVERS}/
WRKSRC=		${WRKDIR}/openid-python-openid-${GITREF}

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://www.openidenabled.com/openid/libraries/python/
COMMENT=	Python module for OpenID
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
