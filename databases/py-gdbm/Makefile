# $NetBSD: Makefile,v 1.16 2002/09/21 23:46:47 jlam Exp $
#

PKGNAME=	${PYPKGPREFIX}-gdbm-0
CATEGORIES=	databases

MAINTAINER=	dolecek@ics.muni.cz
HOMEPAGE=	http://www.python.org/doc/lib/module-gdbm.html
COMMENT=	Python interface to gdbm - GNU database manager

DEPENDS+=	gdbm>=1.7.3:../../databases/gdbm
EVAL_PREFIX+=	GDBMDIR=gdbm

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/gdbmmodule.c
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PY_PATCHPLIST=	yes

PY_SETUP_SUBST+= GDBMPREFIX=${GDBMDIR}

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || true; \
	done)

.include "../../lang/python/srcdist.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
