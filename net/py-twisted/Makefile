# $NetBSD: Makefile,v 1.12 2008/09/16 01:59:07 epg Exp $
#

PKGNAME=		${PYPKGPREFIX}-twisted-${TWISTED_VERSION}
COMMENT=		Framework for writing networked applications
.include "../../net/py-twisted/Makefile.common"

DEPENDS+=		${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=		${PYPKGPREFIX}-ZopeInterface>=3.0.1:../../devel/py-ZopeInterface

do-test:
	cd ${WRKSRC} && ./build/scripts-${PYVERSSUFFIX}/trial twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
