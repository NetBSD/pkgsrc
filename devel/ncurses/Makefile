# $NetBSD: Makefile,v 1.32 2000/10/12 14:56:42 jlam Exp $

DISTNAME=		ncurses-${NC_VERS}
NC_VERS=		5.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=ncurses/} \
			ftp://dickey.his.com/ncurses/ \
			ftp://dickey.his.com/ncurses/${NC_VERS}/
DISTFILES+=		${NC_PATCH}

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://dickey.his.com/ncurses/ncurses.html

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
NC_PATCH=		patch-5.1-20001009.sh

USE_LIBTOOL=		# defined

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

post-extract:
	cd ${WRKSRC} && ${SH} ${DISTDIR}/${DIST_SUBDIR}/${NC_PATCH}
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;

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
