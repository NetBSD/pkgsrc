# $NetBSD: Makefile,v 1.11 2014/05/09 07:37:03 wiz Exp $

DISTNAME=		ZConfig-2.6.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=		devel python
MASTER_SITES=		http://pypi.python.org/packages/source/Z/ZConfig/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.zope.org/Members/fdrake/zconfig/
COMMENT=		Configuration library
#LICENSE=		zope-public-license-v2.1

USE_LANGUAGES=		# empty

INSTALLATION_DIRS+=	share/doc/py-zconfig

PYTHON_VERSIONS_INCOMPATIBLE=	33 34

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/zconfig.pdf \
		${DESTDIR}${PREFIX}/share/doc/py-zconfig

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
