# $NetBSD: Makefile,v 1.19 1999/06/14 00:08:59 cgd Exp $

DISTNAME=		ncurses-1.9.9g
CATEGORIES=		devel
# XXX this should be moved to ftp.netcom.com:/pub/zm/zmbenhal/ncurses/
# XXX once upgraded to the latest version - hubertf
MASTER_SITES=		ftp://ftp.fu-berlin.de/unix/gnu/ncurses/

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/ncurses/ncurses.html

# XXX The following comment is somewhat incorrect.  The package will build
# XXX correctly on alpha, and even build shared libs, but not quite correctly:
# XXX The shlibs have no SONAME, so references to them from programs
# XXX will end up being to libfoo.so.  This may cause upgrade problems in the
# XXX future.  However, an ncurses binary package appeared e.g. with 1.4,
# XXX seemingly built from these bits, so it's probably best to just enable
# XXX it for now.  -- cgd 19990613
#NOT_FOR_PLATFORM=	*-*-alpha	# needs to be libtooled

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-normal --with-shared --enable-bsdpad
WRKSRC=			${WRKDIR}/ncurses_1.9.9g

post-patch:
	( cd ${WRKSRC}/man ; ${RM} -f tput.1 tset.1 clear.1 )
	( cd ${WRKSRC}/man ; for i in *.1m ; do \
	  ${SED} -e '/#include/s/curses.h/ncurses.h/' <$$i >`basename $$i .1m`.1 ; \
	  ${RM} -f $$i ; done )
	( cd ${WRKSRC}/man ; for i in *.3x ; do \
	  ${SED} -e '/#include/s/curses.h/ncurses.h/' <$$i >`basename $$i .3x`.3 ; \
	  ${RM} -f $$i ; done )

post-install:
	${MV} ${PREFIX}/include/curses.h ${PREFIX}/include/ncurses.h
	${RM} -f ${PREFIX}/lib/libcurses.a
	( cd ${PREFIX}/include ; for i in form.h menu.h panel.h ; do \
	  ${SED} '/#include/s|curses.h|ncurses.h|g' $$i >$$i.BAK ; \
	  ${MV} $$i.BAK $$i ; done )

.include "../../mk/bsd.pkg.mk"
