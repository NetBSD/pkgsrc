# $NetBSD: Makefile,v 1.6 2000/06/08 12:57:57 wiz Exp $

DISTNAME=	cscope-15.0bl2
PKGNAME=	cscope-15.0.2
CATEGORIES=	devel
MASTER_SITES=	http://download.sourceforge.net/cscope/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cscope.sourceforge.net/

GNU_CONFIGURE=	YES

OSVER!=		uname -r
GOOD_CURSES=	1.4[S-Z] 1.4Z[A-Z] 1.[5-9]*

.for PATTERN in ${GOOD_CURSES}
.if ${OSVER:M${PATTERN}} != ""
CURSES_GOOD?=
.endif
.endfor

.if !defined(CURSES_GOOD)
DEPENDS+=	ncurses>=5.0:../../devel/ncurses

CONFIGURE_ARGS+=--with-ncurses=${LOCALBASE}

post-extract:
.for FILE in command.c display.c edit.c exec.c find.c help.c input.c main.c
	@cd ${WRKSRC}/src;						\
	${MV} ${FILE} ${FILE}.orig;					\
	${SED} "s/^#include <curses.h>/#include <ncurses.h>/" 		\
		< ${FILE}.orig > ${FILE}
.endfor
.endif

.include "../../mk/bsd.pkg.mk"
