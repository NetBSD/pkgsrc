# $NetBSD: Makefile,v 1.17 2010/11/04 19:40:02 adam Exp $

PKGNAME=	${PYPKGPREFIX}-twisted-${TWISTED_VERSION}
COMMENT=	Framework for writing networked applications
.include "../../net/py-twisted/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=3.0.1:../../devel/py-ZopeInterface

# bin/cftp
CONFLICTS+=		cftp-[0-9]*

REPLACE_PYTHON+=	twisted/mail/test/pop3testserver.py
REPLACE_PYTHON+=	twisted/trial/test/scripttest.py
REPLACE_PYTHON+=	twisted/topfiles/setup.py

post-patch:
	rm ${WRKSRC}/twisted/runner/portmap.c.orig
	rm ${WRKSRC}/twisted/test/generator_failure_tests.py.orig

do-test:
	cd ${WRKSRC} && ./build/scripts-${PYVERSSUFFIX}/trial twisted

# created during self test.
CHECK_FILES_SKIP+=	${PREFIX}/${PYSITELIB}/twisted/plugins/dropin.cache

# egg.mk restricts the Python version list
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
