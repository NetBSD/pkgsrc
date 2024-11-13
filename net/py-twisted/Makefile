# $NetBSD: Makefile,v 1.56 2024/11/13 09:11:39 adam Exp $

.include "../../net/py-twisted/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
COMMENT=	Framework for writing networked applications

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.10.0:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme>=22.5.0:../../devel/py-hatch-fancy-pypi-readme
DEPENDS+=	${PYPKGPREFIX}-attrs>=22.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-automat>=24.8.0:../../devel/py-automat
DEPENDS+=	${PYPKGPREFIX}-constantly>=15.1:../../devel/py-constantly
DEPENDS+=	${PYPKGPREFIX}-hyperlink>=17.1.1:../../www/py-hyperlink
DEPENDS+=	${PYPKGPREFIX}-incremental>=24.7.0:../../devel/py-incremental
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.2.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=5:../../devel/py-zope.interface
# tls
DEPENDS+=	${PYPKGPREFIX}-idna>=2.4:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-service_identity>=18.1.0:../../security/py-service_identity
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
# conch
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.0:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.3:../../security/py-bcrypt
# serial
DEPENDS+=	${PYPKGPREFIX}-serial>=3.0:../../comms/py-serial
# http2
DEPENDS+=	${PYPKGPREFIX}-h2>=3.2:../../www/py-h2
DEPENDS+=	${PYPKGPREFIX}-priority>=1.1.0:../../www/py-priority
TEST_DEPENDS+=	${PYPKGPREFIX}-hamcrest>=2:../../devel/py-hamcrest
TEST_DEPENDS+=	${PYPKGPREFIX}-httpx>=0.27:../../www/py-httpx
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.56:../../devel/py-hypothesis

REPLACE_PYTHON+=	src/twisted/mail/test/pop3testserver.py
REPLACE_PYTHON+=	src/twisted/trial/test/scripttest.py

USE_LANGUAGES=	c99

post-install:
.for bin in cftp ckeygen conch mailmail pyhtmlizer tkconch trial twist twistd
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
