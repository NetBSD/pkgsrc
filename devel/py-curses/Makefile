# $NetBSD: Makefile,v 1.46 2017/09/03 08:53:08 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-curses-${PY_DISTVERSION}
PKGREVISION=	4
CATEGORIES=	devel python

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.python.org/doc/current/lib/module-curses.html
COMMENT=	Curses module for Python

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_cursesmodule.c
PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

# NetBSD-8 curses has enough support for py-curses
USE_CURSES=	getsyx
# But we build as ncurses still to get the full feature set easily
FAKE_NCURSES=	yes

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
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
