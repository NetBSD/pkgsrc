# $NetBSD: Makefile,v 1.4 2011/02/25 09:47:28 wiz Exp $

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

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_ACCEPTED=	27 26 25

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
