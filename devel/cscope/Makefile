# $NetBSD: Makefile,v 1.10 2000/09/27 14:34:12 agc Exp $

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
	@cd ${WRKSRC}/src;						\
	for f in command.c display.c edit.c exec.c find.c help.c	\
			input.c main.c; do				\
		${MV} $$f $$f.orig;					\
		${SED} "s/^#include <curses.h>/#include <ncurses.h>/" 	\
			$$f.orig > $$f;					\
	done
.endif
