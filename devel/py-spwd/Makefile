# $NetBSD: Makefile,v 1.1 2014/02/13 16:10:50 jperkin Exp $

PKGNAME=	${PYPKGPREFIX}-spwd-${PY_DISTVERSION}
CATEGORIES=	devel misc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.python.org/2/library/spwd.html
COMMENT=	Python module to access the Unix shadow password database
LICENSE=	python-software-foundation

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/spwdmodule.c

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
		${PATCH} --batch <$$f || ${TRUE}; \
	done)

.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
