# $NetBSD: Makefile,v 1.3 2011/01/29 20:55:17 gdt Exp $
#

DISTNAME=	foolscap-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	net python
MASTER_SITES=	http://pypi.python.org/packages/source/f/foolscap/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://foolscap.lothar.com/trac
COMMENT=	Foolscap contains an RPC protocol for Twisted
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=3.6.1:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL

PKG_DESTDIR_SUPPORT=	user-destdir

TEST_TARGET=	test

USE_LANGUAGES=	# none

# Why?
PYTHON_VERSIONS_ACCEPTED= 26

INSTALLATION_DIRS+=	share/doc/py-foolscap

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt \
		${DESTDIR}${PREFIX}/share/doc/py-foolscap
	${INSTALL_DATA} ${WRKSRC}/doc/*.xhtml \
		${DESTDIR}${PREFIX}/share/doc/py-foolscap
	${INSTALL_DATA} ${WRKSRC}/doc/*.css \
		${DESTDIR}${PREFIX}/share/doc/py-foolscap
	${INSTALL_DATA} ${WRKSRC}/doc/*.tpl \
		${DESTDIR}${PREFIX}/share/doc/py-foolscap

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
