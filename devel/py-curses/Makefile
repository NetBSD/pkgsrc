# $NetBSD: Makefile,v 1.14 2002/09/21 23:46:48 jlam Exp $
#

PKGNAME=	${PYPKGPREFIX}-curses-0
CATEGORIES=	devel

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/doc/current/lib/module-curses.html
COMMENT=	Curses module for Python

DEPENDS+=	ncurses>=4.2:../../devel/ncurses
EVAL_PREFIX+=	NCURSESDIR=ncurses

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_cursesmodule.c
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PY_PATCHPLIST=	yes

PY_SETUP_SUBST=	NCURSESPREFIX=${NCURSESDIR}

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || true; \
	done)

.include "../../lang/python/srcdist.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
