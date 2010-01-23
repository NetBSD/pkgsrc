# $NetBSD: Makefile,v 1.8 2010/01/23 11:19:03 obache Exp $
#

DISTNAME=		ZConfig-2.6.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=		devel python
MASTER_SITES=		http://pypi.python.org/packages/source/Z/ZConfig/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.zope.org/Members/fdrake/zconfig/
COMMENT=		Configuration library
#LICENSE=		zope-public-license-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty

INSTALLATION_DIRS+=	share/doc/py-zconfig

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/zconfig.pdf \
		${DESTDIR}${PREFIX}/share/doc/py-zconfig

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
