# $NetBSD: Makefile,v 1.14 2012/04/08 19:08:55 wiz Exp $

DISTNAME=	urwid-0.9.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://excess.org/urwid/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://excess.org/urwid/
COMMENT=	Curses-based Python user interface library
LICENSE=	gnu-lgpl-v2.1 # or later

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

REPLACE_PYTHON=	*.py */*.py

FILESEXAMPLES=	bigtext.py \
		browse.py \
		calc.py \
		dialog.py \
		edit.py \
		fib.py \
		graph.py \
		input_test.py \
		test_urwid.py \
		tour.py

DOCDIR=	${PREFIX}/share/doc/py-urwid
EGDIR=	${PREFIX}/share/examples/py-urwid

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/tutorial.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/reference.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${FILESEXAMPLES:S,^,${WRKSRC}/,} ${DESTDIR}${EGDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
