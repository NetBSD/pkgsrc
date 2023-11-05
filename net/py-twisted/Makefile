# $NetBSD: Makefile,v 1.54 2023/11/05 10:38:35 wiz Exp $

.include "../../net/py-twisted/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
COMMENT=	Framework for writing networked applications

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme-[0-9]*:../../devel/py-hatch-fancy-pypi-readme
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=5:../../devel/py-zope.interface
DEPENDS+=	${PYPKGPREFIX}-constantly>=15.1:../../devel/py-constantly
DEPENDS+=	${PYPKGPREFIX}-incremental>=22.10.0:../../devel/py-incremental
DEPENDS+=	${PYPKGPREFIX}-automat>=0.8.0:../../devel/py-automat
DEPENDS+=	${PYPKGPREFIX}-hyperlink>=17.1.1:../../www/py-hyperlink
DEPENDS+=	${PYPKGPREFIX}-attrs>=21.3.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.2.0:../../devel/py-typing-extensions
# tls
DEPENDS+=	${PYPKGPREFIX}-service_identity>=18.1.0:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-idna>=2.4:../../www/py-idna
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
# conch
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.0:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=1.4.0:../../security/py-bcrypt
# serial
DEPENDS+=	${PYPKGPREFIX}-serial>=3.0:../../comms/py-serial
# http2
DEPENDS+=	${PYPKGPREFIX}-h2>=3.0:../../www/py-h2
DEPENDS+=	${PYPKGPREFIX}-priority>=1.1.0:../../www/py-priority
TEST_DEPENDS+=	${PYPKGPREFIX}-hamcrest>=1.9.0:../../devel/py-hamcrest
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

REPLACE_PYTHON+=	src/twisted/mail/test/pop3testserver.py
REPLACE_PYTHON+=	src/twisted/trial/test/scripttest.py

USE_LANGUAGES=	c99

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in cftp ckeygen conch mailmail pyhtmlizer tkconch trial twist twistd
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
