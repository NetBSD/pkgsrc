# $NetBSD: Makefile,v 1.54 2021/12/26 20:03:29 nros Exp $

PKGNAME=	${PYPKGPREFIX}-curses-${PY_DISTVERSION}
PKGREVISION=	6
CATEGORIES=	devel python

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.python.org/doc/current/lib/module-curses.html
COMMENT=	Curses module for Python

PYDISTUTILSPKG=		yes
PY_PATCHPLIST=		yes

# NetBSD-8 curses has enough support for py-curses
USE_CURSES=	getsyx
# But we build as ncurses still to get the full feature set easily
FAKE_NCURSES=	yes

PY_SETUP_SUBST=		NCURSESPREFIX=${BUILDLINK_PREFIX.curses}
PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload

.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
