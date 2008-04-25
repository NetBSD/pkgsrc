# $NetBSD: Makefile,v 1.13 2008/04/25 20:39:08 joerg Exp $
#

PKGNAME=	${PYPKGPREFIX}-cursespanel-0
PKGREVISION=	3
CATEGORIES=	devel python

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.python.org/doc/current/lib/module-curses.html
COMMENT=	Curses panel module for Python

USE_NCURSES=	# filter getsyx getwin has_key immedok mvwinsnstr mvwinsstr ...
# noqiflush pechochar putp putwin qiflush redrawwin setsyx syncok termattrs
# termname tigetflag tigetnum tigetstr tparm typeahead use_env wcursyncup
# wechochar winsnstr winsstr wredrawln wsyncdown wsyncup
EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_curses_panel.c
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED= 25 24 23 21

PY_SETUP_SUBST=	NCURSESPREFIX=${BUILDLINK_PREFIX.ncurses}

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || true; \
	done)

.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../devel/py-curses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
