# $NetBSD: Makefile,v 1.72 2006/10/08 17:16:59 wiz Exp $

DISTNAME=	ncurses-${NC_VERS}
NC_VERS=	5.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=ncurses/} \
		ftp://dickey.his.com/ncurses/ \
		ftp://dickey.his.com/ncurses/${NC_VERS}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dickey.his.com/ncurses/ncurses.html
COMMENT=	CRT screen handling and optimization package

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
USE_TOOLS+=		tbl

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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
PLIST_SUBST+=	NOT_SUNOS="@comment "
TERMINFO_SRC=	${WRKSRC}/misc/terminfo.src
TERMINFODIR=	share/lib/terminfo
.else
PLIST_SUBST+=	NOT_SUNOS=""
TERMINFODIR=	share/terminfo
.endif

PLIST_SUBST+=	TERMINFODIR=${TERMINFODIR:Q}

CONFIGURE_ARGS+=	--with-default-terminfo-dir=${PREFIX}/${TERMINFODIR}
CONFIGURE_ARGS+=	--with-terminfo-dirs=${PREFIX}/${TERMINFODIR}

INSTALLATION_DIRS=	share/examples

.if ${OPSYS} == "SunOS"
SUBST_CLASSES+=		ti
SUBST_STAGE.ti=		post-configure
SUBST_MESSAGE.ti=	Removing screen entries from the terminfo database.
SUBST_FILES.ti=		${TERMINFO_SRC}
SUBST_SED.ti=		-e '/^screen|/,/^$$/d'
SUBST_SED.ti+=		-e '/^screen-w|/,/^$$/d'
SUBST_SED.ti+=		-e '/^screen.teraterm|/,/^$$/d'
.endif

post-configure:
	cd ${WRKSRC}/man;					\
	for f in *.1m; do					\
		${MV} -f $${f} `${BASENAME} $${f} .1m`.1; 	\
	done;							\
	for f in *.3x; do					\
		${MV} -f $${f} `${BASENAME} $${f} .3x`.3; 	\
	done

post-install:
	${INSTALL_DATA} ${WRKSRC}/c++/demo.cc \
		${PREFIX}/share/examples/ncurses++demo.cc

.include "../../mk/bsd.pkg.mk"
