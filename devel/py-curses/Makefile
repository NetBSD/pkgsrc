# $NetBSD: Makefile,v 1.24 2004/07/22 09:16:01 recht Exp $
#

PKGNAME=	${PYPKGPREFIX}-curses-0
PKGREVISION=	2
CATEGORIES=	devel python

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.python.org/doc/current/lib/module-curses.html
COMMENT=	Curses module for Python

USE_BUILDLINK3=	yes
USE_NCURSES=	# filter getsyx getwin has_key immedok mvwinsnstr mvwinsstr ...
# noqiflush pechochar putp putwin qiflush redrawwin setsyx syncok termattrs
# termname tigetflag tigetnum tigetstr tparm typeahead use_env wcursyncup
# wechochar winsnstr winsstr wredrawln wsyncdown wsyncup
EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_cursesmodule.c
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PY_PATCHPLIST=	yes

PY_SETUP_SUBST=	NCURSESPREFIX=${BUILDLINK_PREFIX.ncurses}

BUILDLINK_DEPENDS.python23=	python23>=2.3nb2
BUILDLINK_DEPENDS.python23pth=	python23-pth>=2.3nb2

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || true; \
	done)

.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
