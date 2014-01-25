# $NetBSD: Makefile,v 1.25 2014/01/25 10:30:03 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-cursespanel-${PY_DISTVERSION}
CATEGORIES=	devel python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/doc/current/lib/module-curses.html
COMMENT=	Curses panel module for Python

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

USE_NCURSES=	yes
# filter getsyx getwin has_key immedok mvwinsnstr mvwinsstr ...
# noqiflush pechochar putp putwin qiflush redrawwin setsyx syncok termattrs
# termname tigetflag tigetnum tigetstr tparm typeahead use_env wcursyncup
# wechochar winsnstr winsstr wredrawln wsyncdown wsyncup
EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_curses_panel.c
PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

PY_SETUP_SUBST=	NCURSESPREFIX=${BUILDLINK_PREFIX.ncurses}
PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || ${TRUE}; \
	done)

.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
