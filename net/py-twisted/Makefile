# $NetBSD: Makefile,v 1.11 2008/08/22 21:49:08 epg Exp $
#

PKGNAME=		${PYPKGPREFIX}-twisted-${TWISTED_VERSION}
COMMENT=		Framework for writing networked applications
.include "../../net/py-twisted/Makefile.common"

DEPENDS+=		${PYPKGPREFIX}-OpenSSL>=0.7:../../security/py-OpenSSL
DEPENDS+=		${PYPKGPREFIX}-ZopeInterface>=3.0.1:../../devel/py-ZopeInterface

PYDISTUTILSPKG=		yes

do-test:
	cd ${WRKSRC} && ./build/scripts-${PYVERSSUFFIX}/trial twisted

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
