# $NetBSD: Makefile,v 1.16 2010/03/06 13:18:07 obache Exp $
#

PKGNAME=		${PYPKGPREFIX}-twisted-${TWISTED_VERSION}
COMMENT=		Framework for writing networked applications
.include "../../net/py-twisted/Makefile.common"

DEPENDS+=		${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=		${PYPKGPREFIX}-ZopeInterface>=3.0.1:../../devel/py-ZopeInterface

# bin/cftp
CONFLICTS+=		cftp-[0-9]*

REPLACE_PYTHON+=	twisted/mail/test/pop3testserver.py
REPLACE_PYTHON+=	twisted/trial/test/scripttest.py
REPLACE_PYTHON+=	twisted/topfiles/setup.py

do-test:
	cd ${WRKSRC} && ./build/scripts-${PYVERSSUFFIX}/trial twisted

# created during self test.
CHECK_FILES_SKIP=	${PREFIX}/${PYSITELIB}/twisted/plugins/dropin.cache

# egg.mk restricts the Python version list
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
