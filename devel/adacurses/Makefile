# $NetBSD: Makefile,v 1.4 2019/06/05 07:20:16 nia Exp $

PKGNAME=	adacurses-${ACVERSION}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.invisible-island.net/AdaCurses/
DISTFILES=	AdaCurses-${ACVERSION}.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://invisible-island.net/ncurses/ncurses-Ada95.html
COMMENT=	Ada95 bindings for ncurses
LICENSE=	mit

ACVERSION=	20150808
WRKSRC=		${WRKDIR}/AdaCurses-${ACVERSION}
USE_LANGUAGES=	c ada

MAKE_JOBS_SAFE=	no
USE_TOOLS=	gmake pkg-config

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ada-include=${PREFIX}/include/adacurses \
		--with-ada-objects=${PREFIX}/lib/adacurses \
		--with-curses-dir=${LOCALBASE} \
		--libdir=${PREFIX}/lib/adacurses \
		--enable-widec
PLIST_SUBST=	atic=adacurses/terminal_interface-curses

USE_BUILTIN.ncurses=	no
SUBST_CLASSES=		adagen pragma sample

SUBST_STAGE.adagen=	pre-configure
SUBST_FILES.adagen=	gen/Makefile.in
SUBST_SED.adagen=	-e '/(INSTALL_PROG)/d' -e 's|@ADAGEN_LDFLAGS@||'
SUBST_MESSAGE.adagen=	Adjust gen Makefile

SUBST_STAGE.sample=	pre-configure
SUBST_FILES.sample=	samples/Makefile.in
SUBST_SED.sample=	-e 's|@LIBS@|@LIBS@ -lmenu -lform -lpanel|'
SUBST_MESSAGE.sample=	Adjust samples Makefile

SUBST_STAGE.pragma=	pre-configure
SUBST_FILES.pragma=	gen/terminal_interface-curses.ads.m4 \
			gen/terminal_interface-curses-menus.ads.m4 \
			gen/terminal_interface-curses-forms.ads.m4 \
			gen/terminal_interface-curses-panels.ads.m4
SUBST_SED.pragma=	-e '/pragma Linker_Options/d'
SUBST_MESSAGE.pragma=	Explicitly link form, panel and menu libraries

post-install:
	@${MKDIR} ${DESTDIR}${PREFIX}/lib/gnat
	${INSTALL_SCRIPT} ${WRKSRC}/gen/adacurses-config \
		${DESTDIR}${PREFIX}/bin/
	${SED} "s|@PREFIX@|${LOCALBASE}|g" ${FILESDIR}/adacurses.gpr.in > \
		${DESTDIR}${PREFIX}/lib/gnat/adacurses.gpr

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
