# $NetBSD: Makefile,v 1.8 2000/07/28 10:33:56 wiz Exp $

DISTNAME=	cscope-15.0bl2
PKGNAME=	cscope-15.0.2
CATEGORIES=	devel
MASTER_SITES=	http://download.sourceforge.net/cscope/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cscope.sourceforge.net/

GNU_CONFIGURE=	YES
USE_CURSES=	YES

.include "../../mk/bsd.pkg.mk"

.if ${NEED_NCURSES} == "YES"
CONFIGURE_ARGS+=--with-ncurses=${LOCALBASE}

post-extract:
.for FILE in command.c display.c edit.c exec.c find.c help.c input.c main.c
	@cd ${WRKSRC}/src;						\
	${MV} ${FILE} ${FILE}.orig;					\
	${SED} "s/^#include <curses.h>/#include <ncurses.h>/" 		\
		< ${FILE}.orig > ${FILE}
.endfor
.endif
