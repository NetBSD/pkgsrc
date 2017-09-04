# $NetBSD: Makefile,v 1.16 2017/09/04 18:00:52 wiz Exp $

DISTNAME=		ZConfig-2.6.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=		devel python
MASTER_SITES=		${MASTER_SITE_PYPI:=Z/ZConfig/}

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.zope.org/Members/fdrake/zconfig/
COMMENT=		Configuration library
#LICENSE=		zope-public-license-v2.1

USE_LANGUAGES=		# empty

INSTALLATION_DIRS+=	share/doc/py-zconfig

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/zconfig.pdf \
		${DESTDIR}${PREFIX}/share/doc/py-zconfig

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
