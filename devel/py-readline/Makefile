# $NetBSD: Makefile,v 1.2 2002/09/21 23:46:49 jlam Exp $
#

PKGNAME=	${PYPKGPREFIX}-readline-0
CATEGORIES=	devel misc

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/doc/tut/interacting.html
COMMENT=	line editing support for Python

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/readline.c

USE_GNU_READLINE=	# defined

.include "../../devel/readline/buildlink.mk"

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PY_PATCHPLIST=	yes
PY_SETUP_SUBST+= RLPREFIX=${BUILDLINK_DIR}
PY_SETUP_SUBST+= RLRTPREFIX=${BUILDLINK_PREFIX.readline}

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || true; \
	done)

.include "../../lang/python/srcdist.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
