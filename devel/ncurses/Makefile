# $NetBSD: Makefile,v 1.24 1999/09/04 00:57:48 hubertf Exp $

DISTNAME=		ncurses-4.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=ncurses/} \
			ftp://ftp.clark.net/pub/dickey/ncurses/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/ncurses/ncurses.html

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--with-normal --without-debug --enable-bsdpad
MAKE_ENV+=		NCURSES_MAJOR="${NCURSES_MAJOR}" \
			NCURSES_MINOR="${NCURSES_MINOR}"

# Define these here so they can be conveniently changed when ncurses
# is integrated into the NetBSD source tree.
#
NCURSES_MAJOR=		4
NCURSES_MINOR=		2

post-patch:
	${LN} -sf curses.h ${WRKSRC}/include/ncurses.h
	( cd ${WRKSRC}/man ; ${RM} -f clear.1 tput.1 tset.1 )
	( cd ${WRKSRC}/man ; for i in *.1m ; do \
	  ${SED} -e '/#include/s/curses.h/ncurses.h/' \
		<$$i >`basename $$i .1m`.1; \
	  ${RM} -f $$i; done )
	( cd ${WRKSRC}/man ; for i in *.3x ; do \
	  ${SED} -e '/#include/s/curses.h/ncurses.h/' \
		<$$i >`basename $$i .3x`.3; \
	  ${RM} -f $$i; done )

.include "../../mk/bsd.pkg.mk"
