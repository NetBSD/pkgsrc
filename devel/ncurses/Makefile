# $NetBSD: Makefile,v 1.38.2.1 2002/05/11 02:09:04 jlam Exp $

DISTNAME=		ncurses-${NC_VERS}
NC_VERS=		5.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=ncurses/} \
			ftp://dickey.his.com/ncurses/ \
			ftp://dickey.his.com/ncurses/${NC_VERS}/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://dickey.his.com/ncurses/ncurses.html
COMMENT=		CRT screen handling and optimization package

USE_LIBTOOL=		# defined
USE_BUILDLINK2_ONLY=	# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-libtool
CONFIGURE_ARGS+=	--enable-bsdpad
CONFIGURE_ARGS+=	--with-cxx-binding
CONFIGURE_ARGS+=	--without-ada
CONFIGURE_ARGS+=	--without-curses-h
CONFIGURE_ARGS+=	--without-gpm
CONFIGURE_ARGS+=	--with-manpage-format=normal
CONFIGURE_ARGS+=	--with-manpage-tbl

# Remove these manpages from the distribution so they won't get installed
CURSES_NO_MAN=		clear.1 tput.1 tset.1

post-configure:
	cd ${WRKSRC}/man;					\
	${RM} -f ${CURSES_NO_MAN};				\
	for file in *.1m; do					\
		${MV} -f $${file} `basename $${file} .1m`.1; 	\
	done;							\
	for file in *.3x; do					\
		${MV} -f $${file} `basename $${file} .3x`.3; 	\
	done

post-install:
	${INSTALL_DATA} ${WRKSRC}/c++/demo.cc \
		${PREFIX}/share/examples/ncurses++demo.cc

.include "../../mk/bsd.pkg.mk"
