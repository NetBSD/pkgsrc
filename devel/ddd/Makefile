# $NetBSD: Makefile,v 1.87 2022/06/28 11:31:42 wiz Exp $
#

DISTNAME=	ddd-3.3.12
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=ddd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/ddd/
COMMENT=	Data Display Debugger -- graphical front-end for GDB/DBX/XDB

LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		YES
INFO_FILES=		YES # PLIST
TEST_TARGET=		check
BUILD_DEFS+=		PAPERSIZE
USE_TOOLS+=		gmake gzip
USE_LANGUAGES=		c c++
TOOLS_BROKEN+=		perl

CONFIGURE_ARGS+=	--with-ncurses=no
CONFIGURE_ENV+=		COMPFACE=${FALSE:Q}

.include "../../mk/bsd.prefs.mk"

CXXFLAGS.SunOS+=	-fpermissive

INSTALLATION_DIRS+=	share/doc/ddd

# Default paper size is A4
.if !empty(PAPERSIZE:MLetter*)
SUBST_CLASSES+=			set-papersize
SUBST_STAGE.set-papersize=	pre-configure
SUBST_MESSAGE.set-papersize=	Setting papersize for program documentation to ${PAPERSIZE}.
SUBST_FILES.set-papersize=	ddd/Ddd.in
SUBST_SED.set-papersize=	-e 's|@Ddd@\*paperSize: 210mm x 297mm|@Ddd@*paperSize: 8.5" x 11"|'
.endif

post-configure:
	${ECHO} LIBXM = ${MOTIFLIB:Q} >> ${WRKSRC:Q}/ddd/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC:Q}/README ${DESTDIR}${PREFIX:Q}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC:Q}/doc/ddd-paper.ps ${DESTDIR}${PREFIX:Q}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC:Q}/doc/ddd.pdf ${DESTDIR}${PREFIX:Q}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC:Q}/doc/ddd-themes.pdf ${DESTDIR}${PREFIX:Q}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC:Q}/doc/html/ddd.html ${DESTDIR}${PREFIX:Q}/share/doc/ddd
	${GZIP_CMD} ${DESTDIR}${PREFIX:Q}/share/doc/ddd/ddd-paper.ps

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
