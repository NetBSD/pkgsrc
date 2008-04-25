# $NetBSD: Makefile,v 1.27 2008/04/25 18:28:33 joerg Exp $
#

PKGNAME=	${PYPKGPREFIX}-idle-0
PKGREVISION=	2
CATEGORIES=	devel python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/idle/
COMMENT=	IDLE - The Integrated DeveLopment Environment for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SRC=	${WRKDIR}/.PLIST_SRC
PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || ${TRUE}; \
	done)

#
# With Python-2.3 and up, the Idle code is part of the base library.
# We just install a wrapper script. Also, threads are required now.
# NOTE: if you add a new version of Python here, add to the following test
#
PYTHON_VERSIONS_ACCEPTED=	25 24 23 21
.include "../../lang/python/extension.mk"
.if (${PYPKGPREFIX} != "py23") && (${PYPKGPREFIX} != "py24") && (${PYPKGPREFIX} != "py25")

EXTRACT_ELEMENTS=	${PYSUBDIR}/Tools/idle/*
PYTHON_PATCH_SCRIPTS=	Tools/idle/idle.py
INSTALLATION_DIRS=	bin ${PYSITELIB}

do-build:
	${PYTHONBIN} ${LOCALBASE}/${PYLIB}/compileall.py ${WRKSRC}/Tools/idle

do-install:
	${CP} -r ${WRKSRC}/Tools/idle ${DESTDIR}${PREFIX}/${PYSITELIB}
	${CHMOD} +x ${DESTDIR}${PREFIX}/${PYSITELIB}/idle/idle.py
	${LN} -sf ${PREFIX}/${PYSITELIB}/idle/idle.py \
		${DESTDIR}${PREFIX}/bin/idle${PYVERSSUFFIX}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${DESTDIR}${PREFIX}; ${FIND} ${PYSITELIB}/idle -type f -print \
		>>${PLIST_SRC})
	(cd ${DESTDIR}${PREFIX}; ${FIND} -d ${PYSITELIB}/idle -type d -print | \
		${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.else # py23 and up

EXTRACT_ELEMENTS=	${PYSUBDIR}/Tools/scripts/idle
PYTHON_PATCH_SCRIPTS= Tools/scripts/idle
NO_BUILD=	yes
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Tools/scripts/idle \
		${DESTDIR}${PREFIX}/bin/idle${PYVERSSUFFIX}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}

.endif # py23 and up

.include "../../lang/python/srcdist.mk"
.include "../../lang/python/application.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
