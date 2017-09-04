# $NetBSD: Makefile,v 1.3 2017/09/04 18:08:21 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-spwd-${PY_DISTVERSION}
CATEGORIES=	devel misc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.python.org/2/library/spwd.html
COMMENT=	Python module to access the Unix shadow password database
LICENSE=	python-software-foundation

# Only appropriate for platforms with /etc/shadow and getsp*()
ONLY_FOR_PLATFORM=	Linux-*-* SunOS-*-*

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
