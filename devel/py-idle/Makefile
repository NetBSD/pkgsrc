# $NetBSD: Makefile,v 1.29 2011/10/16 07:19:33 obache Exp $
#

PKGNAME=	${PYPKGPREFIX}-idle-0
PKGREVISION=	2
CATEGORIES=	devel python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/idle/
COMMENT=	IDLE - The Integrated DeveLopment Environment for Python

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

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
.include "../../lang/python/extension.mk"

EXTRACT_ELEMENTS=	${PYSUBDIR}/Tools/scripts/idle
PYTHON_PATCH_SCRIPTS= Tools/scripts/idle
NO_BUILD=	yes
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Tools/scripts/idle \
		${DESTDIR}${PREFIX}/bin/idle${PYVERSSUFFIX}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}

.include "../../lang/python/srcdist.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
