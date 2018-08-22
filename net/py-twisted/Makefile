# $NetBSD: Makefile,v 1.39 2018/08/22 09:46:06 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
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
DEPENDS+=	${PYPKGPREFIX}-service_identity-[0-9]*:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-idna>=2.4:../../www/py-idna

REPLACE_PYTHON+=	src/twisted/mail/test/pop3testserver.py
REPLACE_PYTHON+=	src/twisted/trial/test/scripttest.py
REPLACE_PYTHON+=	src/twisted/python/test/pullpipe.py

USE_LANGUAGES=		c99

.include "../../lang/python/pyversion.mk"
# Temporary fix for Python 3.7: omit files that do not compile
PLIST_VARS+=		async
.if ${_PYTHON_VERSION} != "37"
PLIST.async=		yes
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	for i in cftp ckeygen conch mailmail pyhtmlizer tkconch trial twist twistd; do \
		${MV} $$i $$i-${PYVERSSUFFIX} || ${TRUE}; \
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
