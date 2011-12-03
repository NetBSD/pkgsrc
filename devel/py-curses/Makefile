# $NetBSD: Makefile,v 1.36 2011/12/03 00:02:14 joerg Exp $
#

PKGNAME=	${PYPKGPREFIX}-curses-0
PKGREVISION=	5
CATEGORIES=	devel python

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.python.org/doc/current/lib/module-curses.html
COMMENT=	Curses module for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCLUDE_3X=	yes

USE_NCURSES=	yes
# needs: filter getsyx getwin has_key immedok mvwinsnstr mvwinsstr ...
# noqiflush pechochar putp putwin qiflush redrawwin setsyx syncok termattrs
# termname tigetflag tigetnum tigetstr tparm typeahead use_env wcursyncup
# wechochar winsnstr winsstr wredrawln wsyncdown wsyncup
EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_cursesmodule.c
PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

PY_SETUP_SUBST=	NCURSESPREFIX=${BUILDLINK_PREFIX.ncurses}
PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload

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
