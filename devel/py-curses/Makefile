# $NetBSD: Makefile,v 1.11 2000/10/22 20:01:52 tsarna Exp $
#

DISTNAME=	${PY_DISTNAME}
PKGNAME=	py-curses-${PY_VERSION}
WRKSRC=		${PY_WRKSRC}
CATEGORIES=	devel
MASTER_SITES=	${PY_MASTER_SITES}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/doc/current/lib/module-curses.html

DEPENDS+=	ncurses>=4.2:../../devel/ncurses

EXTRACT_ELEMENTS=	${PY_MODULES}/_cursesmodule.c

do-configure:	python-std-do-configure

do-install:
	${INSTALL_DATA} ${WRKSRC}/_cursesmodule.so ${PY_LIBDIR}/lib-dynload

.include "../../lang/python/Makefile.inc"
.include "../../mk/bsd.pkg.mk"
