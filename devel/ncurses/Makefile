# $NetBSD: Makefile,v 1.62 2004/10/03 00:13:31 tv Exp $

DISTNAME=	ncurses-${NC_VERS}
PKGREVISION=	1
NC_VERS=	5.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=ncurses/} \
		ftp://dickey.his.com/ncurses/ \
		ftp://dickey.his.com/ncurses/${NC_VERS}/

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://dickey.his.com/ncurses/ncurses.html
COMMENT=	CRT screen handling and optimization package

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-libtool
CONFIGURE_ARGS+=	--enable-bsdpad
CONFIGURE_ARGS+=	--enable-overwrite
CONFIGURE_ARGS+=	--with-cxx-binding
CONFIGURE_ARGS+=	--without-ada
CONFIGURE_ARGS+=	--without-curses-h
CONFIGURE_ARGS+=	--without-gpm
CONFIGURE_ARGS+=	--with-manpage-format=normal
CONFIGURE_ARGS+=	--with-manpage-tbl

USE_GNU_TOOLS+=		awk
USE_TBL=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
PLIST_SUBST+=	NOT_SUNOS="@comment "
TERMINFO_SRC=	${WRKSRC}/misc/terminfo.src
TERMINFODIR=	share/lib/terminfo
.else
PLIST_SUBST+=	NOT_SUNOS=""
TERMINFODIR=	share/terminfo
.endif

PLIST_SUBST+=	TERMINFODIR="${TERMINFODIR}"

CONFIGURE_ARGS+=	--with-default-terminfo-dir=${PREFIX}/${TERMINFODIR}
CONFIGURE_ARGS+=	--with-terminfo-dirs=${PREFIX}/${TERMINFODIR}

INSTALLATION_DIRS=	share/examples

post-configure:
	cd ${WRKSRC}/man;					\
	for f in *.1m; do					\
		${MV} -f $${f} `${BASENAME} $${f} .1m`.1; 	\
	done;							\
	for f in *.3x; do					\
		${MV} -f $${f} `${BASENAME} $${f} .3x`.3; 	\
	done
.if ${OPSYS} == "SunOS"
	${MV} ${TERMINFO_SRC} ${TERMINFO_SRC}.old
	${SED} -e "/^screen|/,/^$$/d"  -e "/^screen-w|/,/^$$/d" \
	    -e "/^screen.teraterm|/,/^$$/d" \
	   <${TERMINFO_SRC}.old >${TERMINFO_SRC}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/c++/demo.cc \
		${PREFIX}/share/examples/ncurses++demo.cc

.include "../../mk/bsd.pkg.mk"
