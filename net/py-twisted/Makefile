# $NetBSD: Makefile,v 1.34 2017/06/21 18:35:35 adam Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
COMMENT=	Framework for writing networked applications
.include "../../net/py-twisted/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-automat-[0-9]*:../../devel/py-automat
DEPENDS+=	${PYPKGPREFIX}-constantly-[0-9]*:../../devel/py-constantly
DEPENDS+=	${PYPKGPREFIX}-hyperlink-[0-9]*:../../www/py-hyperlink
DEPENDS+=	${PYPKGPREFIX}-incremental-[0-9]*:../../devel/py-incremental
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-service_identity-[0-9]*:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=3.0.1:../../devel/py-ZopeInterface

REPLACE_PYTHON+=	src/twisted/mail/test/pop3testserver.py
REPLACE_PYTHON+=	src/twisted/trial/test/scripttest.py
REPLACE_PYTHON+=	src/twisted/python/test/pullpipe.py

CFLAGS.SunOS+=	-D_XOPEN_SOURCE=1 -D_XOPEN_SOURCE_EXTENDED=1 -Du_int=uint32_t

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	for i in cftp ckeygen conch mailmail pyhtmlizer tkconch trial twist twistd; do \
		${MV} $$i $$i-${PYVERSSUFFIX}; \
	done

# Do not "make package" after running "make test"; this will result in files
# being installed that should not be.
do-test:
	cd ${WRKSRC} && ./build/scripts-${PYVERSSUFFIX}/trial twisted

# created during self test.
CHECK_FILES_SKIP+=	${PREFIX}/${PYSITELIB}/twisted/plugins/dropin.cache

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
