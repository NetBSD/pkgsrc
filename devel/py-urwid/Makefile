# $NetBSD: Makefile,v 1.16 2013/05/15 22:35:31 wiz Exp $

DISTNAME=	urwid-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://excess.org/urwid/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://excess.org/urwid/
COMMENT=	Curses-based Python user interface library
LICENSE=	gnu-lgpl-v2.1 # or later

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

REPLACE_PYTHON=	*.py */*.py

FILESEXAMPLES=	\
		bigtext.py \
		browse.py \
		calc.py \
		dialog.py \
		edit.py \
		fib.py \
		graph.py \
		input_test.py \
		lcd_cf635.py \
		palette_test.py \
		pop_up.py \
		subproc.py \
		subproc2.py \
		terminal.py \
		tour.py \
		treesample.py \
		twisted_serve_ssh.py \
		twisted_serve_ssh.tac

DOCDIR=	${PREFIX}/share/doc/py-urwid
EGDIR=	${PREFIX}/share/examples/py-urwid

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

post-install:
	${INSTALL_DATA} ${FILESEXAMPLES:S,^,${WRKSRC}/examples/,} ${DESTDIR}${EGDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
