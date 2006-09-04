# $NetBSD: Makefile,v 1.72 2006/09/04 08:56:09 martti Exp $
#

DISTNAME=	ddd-3.3.11
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=ddd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/ddd/
COMMENT=	Data Display Debugger -- graphical front-end for GDB/DBX/XDB

GNU_CONFIGURE=		YES
INFO_FILES=		# PLIST
TEST_TARGET=		check
USE_TOOLS+=		gmake gzip
USE_LANGUAGES=		c c++
USE_X11BASE=		YES

GCC_REQD+=		3.0

CONFIGURE_ARGS+=	--with-ncurses=no
CONFIGURE_ENV+=		COMPFACE=${FALSE:Q}

.include "../../mk/bsd.prefs.mk"

post-patch:
	@case ${PAPERSIZE:Q} in					\
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
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC:Q}/README ${PREFIX:Q}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC:Q}/doc/ddd-paper.ps ${PREFIX:Q}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC:Q}/doc/ddd.ps ${PREFIX:Q}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC:Q}/doc/ddd.pdf ${PREFIX:Q}/share/doc/ddd
	${GZIP_CMD} ${PREFIX:Q}/share/doc/ddd/ddd-paper.ps
	${GZIP_CMD} ${PREFIX:Q}/share/doc/ddd/ddd.ps

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
