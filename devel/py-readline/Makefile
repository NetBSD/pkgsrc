# $NetBSD: Makefile,v 1.3 2002/10/25 18:31:33 wiz Exp $
#

PKGNAME=	${PYPKGPREFIX}-readline-0
CATEGORIES=	devel misc

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/doc/tut/interacting.html
COMMENT=	line editing support for Python

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/readline.c

USE_BUILDLINK2=		# defined
USE_GNU_READLINE=	# defined

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PY_PATCHPLIST=	yes
PY_SETUP_SUBST+= RLRTPREFIX=${BUILDLINK_PREFIX.readline}

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || true; \
	done)

.include "../../devel/readline/buildlink2.mk"
.include "../../lang/python/srcdist.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
