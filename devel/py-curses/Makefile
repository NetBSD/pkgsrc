# $NetBSD: Makefile,v 1.31 2006/06/17 17:31:08 rillig Exp $
#

PKGNAME=	${PYPKGPREFIX}-curses-0
PKGREVISION=	4
CATEGORIES=	devel python

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.python.org/doc/current/lib/module-curses.html
COMMENT=	Curses module for Python

USE_NCURSES=	yes
# needs: filter getsyx getwin has_key immedok mvwinsnstr mvwinsstr ...
# noqiflush pechochar putp putwin qiflush redrawwin setsyx syncok termattrs
# termname tigetflag tigetnum tigetstr tparm typeahead use_env wcursyncup
# wechochar winsnstr winsstr wredrawln wsyncdown wsyncup
EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_cursesmodule.c
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PY_PATCHPLIST=	yes

PY_SETUP_SUBST=	NCURSESPREFIX=${BUILDLINK_PREFIX.ncurses}

BUILDLINK_API_DEPENDS.python23+=	python23>=2.3nb2

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	set -e;								\
	cd ${WRKSRC};							\
	for f in ${PATCHDIR}/patch-*; do				\
		${PATCH} --batch < "$$f" || ${TRUE};			\
	done

.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
