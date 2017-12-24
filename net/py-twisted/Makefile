# $NetBSD: Makefile,v 1.37 2017/12/24 13:44:56 wiedi Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
COMMENT=	Framework for writing networked applications
.include "../../net/py-twisted/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-automat>=0.3.0:../../devel/py-automat
DEPENDS+=	${PYPKGPREFIX}-constantly>=15.1:../../devel/py-constantly
DEPENDS+=	${PYPKGPREFIX}-hyperlink>=17.1.1:../../www/py-hyperlink
DEPENDS+=	${PYPKGPREFIX}-idna>=2.4:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-incremental>=16.10.1:../../devel/py-incremental
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=16.0.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-service_identity-[0-9]*:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=3.0.1:../../devel/py-ZopeInterface

REPLACE_PYTHON+=	src/twisted/mail/test/pop3testserver.py
REPLACE_PYTHON+=	src/twisted/trial/test/scripttest.py
REPLACE_PYTHON+=	src/twisted/python/test/pullpipe.py

USE_LANGUAGES=		c99

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	for i in cftp ckeygen conch mailmail pyhtmlizer tkconch trial twist twistd; do \
		${MV} $$i $$i-${PYVERSSUFFIX} || ${TRUE}; \
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
