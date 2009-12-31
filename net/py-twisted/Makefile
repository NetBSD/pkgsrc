# $NetBSD: Makefile,v 1.15 2009/12/31 08:37:32 wiz Exp $
#

PKGNAME=		${PYPKGPREFIX}-twisted-${TWISTED_VERSION}
COMMENT=		Framework for writing networked applications
.include "../../net/py-twisted/Makefile.common"

DEPENDS+=		${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=		${PYPKGPREFIX}-ZopeInterface>=3.0.1:../../devel/py-ZopeInterface

# bin/cftp
CONFLICTS+=		cftp-[0-9]*

REPLACE_PYTHON+=	${WRKSRC}/twisted/mail/test/pop3testserver.py
REPLACE_PYTHON+=	${WRKSRC}/twisted/trial/test/scripttest.py

do-test:
	cd ${WRKSRC} && ./build/scripts-${PYVERSSUFFIX}/trial twisted

# egg.mk restricts the Python version list
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
