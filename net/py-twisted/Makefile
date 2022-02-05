# $NetBSD: Makefile,v 1.47 2022/02/05 14:27:12 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
COMMENT=	Framework for writing networked applications
.include "../../net/py-twisted/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-attrs>=17.4.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-automat>=0.3.0:../../devel/py-automat
DEPENDS+=	${PYPKGPREFIX}-constantly>=15.1:../../devel/py-constantly
DEPENDS+=	${PYPKGPREFIX}-hamcrest>=1.9.0:../../devel/py-hamcrest
DEPENDS+=	${PYPKGPREFIX}-hyperlink>=17.1.1:../../www/py-hyperlink
DEPENDS+=	${PYPKGPREFIX}-incremental>=16.10.1:../../devel/py-incremental
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=4.4.2:../../devel/py-ZopeInterface
# TLS
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=16.0.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-service_identity>=18.1.0:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-idna>=2.4:../../www/py-idna

REPLACE_PYTHON+=	src/twisted/mail/test/pop3testserver.py
REPLACE_PYTHON+=	src/twisted/trial/test/scripttest.py

USE_LANGUAGES=	c99

USE_PKG_RESOURCES=	yes

post-install:
.for bin in cftp ckeygen conch mailmail pyhtmlizer tkconch trial twist twistd
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
