# $NetBSD: Makefile,v 1.8 2004/04/27 04:59:42 snj Exp $
#

PKGNAME=	${PYPKGPREFIX}-readline-0
CATEGORIES=	devel misc

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.python.org/doc/tut/interacting.html
COMMENT=	Line editing support for Python

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/readline.c

USE_BUILDLINK3=		yes
USE_GNU_READLINE=	# defined

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PY_PATCHPLIST=	yes
PY_SETUP_SUBST+= RLPREFIX=${BUILDLINK_PREFIX.readline}
PY_SETUP_SUBST+= RLRTPREFIX=${BUILDLINK_PREFIX.readline}

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || true; \
	done)

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
