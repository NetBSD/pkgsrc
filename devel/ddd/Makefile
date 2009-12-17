# $NetBSD: Makefile,v 1.74 2009/12/17 21:31:43 abs Exp $
#

DISTNAME=	ddd-3.3.11
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=ddd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/ddd/
COMMENT=	Data Display Debugger -- graphical front-end for GDB/DBX/XDB

GNU_CONFIGURE=		YES
INFO_FILES=		YES # PLIST
TEST_TARGET=		check
BUILD_DEFS+=		PAPERSIZE
USE_TOOLS+=		gmake gzip
USE_LANGUAGES=		c c++
USE_X11BASE=		YES

GCC_REQD+=		3.0

CONFIGURE_ARGS+=	--with-ncurses=no
CONFIGURE_ENV+=		COMPFACE=${FALSE:Q}

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS+= share/doc/ddd

post-patch:
	case ${PAPERSIZE:Q} in					\
	A4)	${ECHO} "Using A4 paper size" ;;		\
	Letter*)	${ECHO} "Using US Letter paper size";	\
		${MV} ${WRKSRC:Q}/ddd/Ddd.in ${WRKSRC:Q}/ddd/Ddd.in.orig; \
		${SED} -e 's|@Ddd@\*paperSize: 210mm x 297mm|@Ddd@*paperSize: 8.5" x 11"|' \
			< ${WRKSRC:Q}/ddd/Ddd.in.orig 		\
			> ${WRKSRC:Q}/ddd/Ddd.in ;;		\
	"")	${ECHO} "PAPERSIZE not set - defaulting to A4" ;;	\
	*)	${ECHO} "Bad PAPERSIZE - $$PAPERSIZE - defaulting to A4" ;; \
	esac;

post-configure:
	${ECHO} LIBXM = ${MOTIFLIB:Q} >> ${WRKSRC:Q}/ddd/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC:Q}/README ${DESTDIR}${PREFIX:Q}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC:Q}/doc/ddd-paper.ps ${DESTDIR}${PREFIX:Q}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC:Q}/doc/ddd.ps ${DESTDIR}${PREFIX:Q}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC:Q}/doc/ddd.pdf ${DESTDIR}${PREFIX:Q}/share/doc/ddd
	${GZIP_CMD} ${DESTDIR}${PREFIX:Q}/share/doc/ddd/ddd-paper.ps
	${GZIP_CMD} ${DESTDIR}${PREFIX:Q}/share/doc/ddd/ddd.ps

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
