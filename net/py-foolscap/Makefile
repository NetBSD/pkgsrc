# $NetBSD: Makefile,v 1.44 2024/08/11 19:44:49 gdt Exp $

DISTNAME=	foolscap-23.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
# pypi lacks a source archive
# https://github.com/warner/foolscap/issues/107
GITHUB_PROJECT=	foolscap
# \todo Hoist this as a fix to github.mk.
GITHUB_TAG=	refs/tags/${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=warner/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/warner/foolscap
COMMENT=	RPC protocol for Twisted
LICENSE=	mit

# github tarball unpacks to a strange path.
# https://github.com/warner/foolscap/issues/106
WRKSRC=		${WRKDIR}/foolscap-${DISTNAME}

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=3.6.1:../../devel/py-zope.interface

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/doc/py-foolscap

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt \
		${DESTDIR}${PREFIX}/share/doc/py-foolscap
	${INSTALL_DATA} ${WRKSRC}/doc/*.rst \
		${DESTDIR}${PREFIX}/share/doc/py-foolscap

.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
