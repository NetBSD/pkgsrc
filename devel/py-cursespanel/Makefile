# $NetBSD: Makefile,v 1.34 2020/01/08 13:44:41 joerg Exp $

PKGNAME=	${PYPKGPREFIX}-cursespanel-${PY_DISTVERSION}
PKGREVISION=	4
CATEGORIES=	devel python

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.python.org/doc/current/lib/module-curses.html
COMMENT=	Curses panel module for Python

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

USE_CURSES=	getsyx
FAKE_NCURSES=	yes

PYDISTUTILSPKG=		yes

PY_SETUP_SUBST=		NCURSESPREFIX=${BUILDLINK_PREFIX.ncurses}
PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload

.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
