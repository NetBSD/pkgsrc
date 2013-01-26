# $NetBSD: Makefile,v 1.12 2013/01/26 21:37:33 adam Exp $

DISTNAME=	fltk-1.1.7-source
PKGNAME=	fltk-sudoku-1.1.7
PKGREVISION=	6
VERS=		${DISTNAME:S/fltk-//:S/-source//}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fltk/} \
		ftp://ftp2.easysw.com/pub/fltk/${VERS}/ \
		ftp://ftp3.easysw.com/pub/fltk/${VERS}/ \
		http://ftp.easysw.com/pub/fltk/${VERS}/ \
		http://mirror.nu6.org/ftp.easysw.com/pub/fltk/${VERS}/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/fltk/${VERS}/ \
		ftp://ftp.rz.tu-bs.de/pub/mirror/ftp.easysw.com/ftp/pub/fltk/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.easysw.com/~mike/sudoku/index.html
COMMENT=	FLTK example Sudoku game creator and solver

WRKSRC=			${WRKDIR}/${DISTNAME:S/-source//}
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

PTHREAD_OPTS+=		require
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libtool=${LIBTOOL:Q}
CONFIGURE_ARGS+=	--enable-threads

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-configure
SUBST_MESSAGE.config=	Adjusting paths to fltk libraries in configure result
SUBST_FILES.config=	makeinclude fltk-config
SUBST_SED.config=	-e "s|../lib/|${PREFIX}/lib/|g"

SUBST_CLASSES+=		config2
SUBST_STAGE.config2=	post-configure
SUBST_MESSAGE.config2=	Adjusting paths to fltk libraries in Sudoku's Makefile
SUBST_FILES.config2=	test/Makefile
SUBST_SED.config2=	-e "s|../lib/||g"

BUILD_DIRS=		test
BUILD_TARGET=		sudoku

INSTALLATION_DIRS=	bin

SETGIDGAME=		yes
SPECIAL_PERMS=		bin/fltk-sudoku ${SETGID_GAMES_PERMS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/test/sudoku ${DESTDIR}${PREFIX}/bin/fltk-sudoku

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
