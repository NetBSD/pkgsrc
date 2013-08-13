# $NetBSD: Makefile,v 1.22 2013/08/13 17:47:41 adam Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
COMMENT=	Framework for writing networked applications
.include "../../net/py-twisted/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=3.0.1:../../devel/py-ZopeInterface

# bin/cftp
CONFLICTS+=		cftp-[0-9]*

REPLACE_PYTHON+=	twisted/mail/test/pop3testserver.py
REPLACE_PYTHON+=	twisted/trial/test/scripttest.py
REPLACE_PYTHON+=	twisted/topfiles/setup.py
REPLACE_PYTHON+=	twisted/python/test/pullpipe.py

CFLAGS.SunOS+=	-D_XOPEN_SOURCE=1 -D_XOPEN_SOURCE_EXTENDED=1 -Du_int=uint32_t

# twisted will install files present in the source directory even
# though they were not in the tarball.  Therefore, we must clean the
# .orig files from patches.  This is done pre-install rather than
# post-patch so that mkpatches(1) will still work.
pre-install:
	rm -f ${WRKSRC}/twisted/runner/portmap.c.orig

# Do not "make package" after running "make test"; this will result in files
# being installed that should not be.
do-test:
	cd ${WRKSRC} && ./build/scripts-${PYVERSSUFFIX}/trial twisted

# created during self test.
CHECK_FILES_SKIP+=	${PREFIX}/${PYSITELIB}/twisted/plugins/dropin.cache

# egg.mk restricts the Python version list
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"

# With python 2.6, twisted builds an additional object.
# XXX Guess that 2.5 does this too.
PLIST_VARS+=		initgroups
.if ${PYPKGPREFIX} == "py26" || ${PYPKGPREFIX} == "py25"
PLIST.initgroups=	YES
.endif

.include "../../mk/bsd.pkg.mk"
