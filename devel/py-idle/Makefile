# $NetBSD: Makefile,v 1.3 2002/01/29 11:12:47 drochner Exp $
#

PKGNAME=	${PYPKGPREFIX}-idle-0
CATEGORIES=	devel

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.python.org/idle/
COMMENT=	IDLE - The Integrated DeveLopment Environment for Python

USE_X11=	yes

EXTRACT_ELEMENTS=	${PYSUBDIR}/Tools/idle/*

PYTHON_PATCH_SCRIPTS= ${WRKSRC}/Tools/idle/idle.py
PLIST_SRC=	${WRKDIR}/.PLIST_SRC
PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || true; \
	done)

do-build:
	${PYTHONBIN} ${LOCALBASE}/${PYLIB}/compileall.py ${WRKSRC}/Tools/idle

do-install:
	${CP} -r ${WRKSRC}/Tools/idle ${PREFIX}/${PYSITELIB}
	${CHMOD} +x ${PREFIX}/${PYSITELIB}/idle/idle.py
	${LN} -sf ${PREFIX}/${PYSITELIB}/idle/idle.py \
		${PREFIX}/bin/idle${PYVERSSUFFIX}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} ${PYSITELIB}/idle -type f -print \
		>>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${PYSITELIB}/idle -type d -print | \
		${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../lang/python/extension.buildlink.mk"
.include "../../lang/python/application.buildlink.mk"
.include "../../lang/python/srcdist.mk"
.include "../../x11/py-Tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
