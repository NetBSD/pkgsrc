# $NetBSD: Makefile,v 1.23 2006/02/05 23:08:35 joerg Exp $
#

PKGNAME=	${PYPKGPREFIX}-gdbm-0
PKGREVISION=	2
CATEGORIES=	databases python

MAINTAINER=	dolecek@ics.muni.cz
HOMEPAGE=	http://www.python.org/doc/lib/module-gdbm.html
COMMENT=	Python interface to gdbm - GNU database manager

EVAL_PREFIX+=	GDBMDIR=gdbm

USE_TOOLS+=	patch

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

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
