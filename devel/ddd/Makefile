# $NetBSD: Makefile,v 1.54 2003/09/17 19:40:11 grant Exp $
#

DISTNAME=	ddd-3.3.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=ddd/}

MAINTAINER=     martti@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/ddd/
COMMENT=	Data Display Debugger -- a common graphical front-end for GDB/DBX/XDB

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
TEST_TARGET=		check
INFO_FILES=		ddd-themes.info ddd.info

GCC_REQD=		3.0

CONFIGURE_ARGS+=	--with-ncurses=no
CONFIGURE_ENV+=		COMPFACE="${FALSE}"

.include "../../mk/bsd.prefs.mk"

post-patch:
	@case "${PAPERSIZE}" in					\
	A4)	${ECHO} "Using A4 paper size" ;;		\
	Letter*)	${ECHO} "Using US Letter paper size";	\
		${MV} ${WRKSRC}/ddd/Ddd.in ${WRKSRC}/ddd/Ddd.in.orig; \
		${SED} -e 's|@Ddd@\*paperSize: 210mm x 297mm|@Ddd@*paperSize: 8.5" x 11"|' \
			< ${WRKSRC}/ddd/Ddd.in.orig 		\
			> ${WRKSRC}/ddd/Ddd.in ;;		\
	"")	${ECHO} "PAPERSIZE not set - defaulting to A4" ;;	\
	*)	${ECHO} "Bad PAPERSIZE - $$PAPERSIZE - defaulting to A4" ;; \
	esac;

post-configure:
	${ECHO} "LIBXM = ${MOTIFLIB}" >> ${WRKSRC}/ddd/Makefile

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/ddd-paper.ps ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/ddd.ps ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/ddd.pdf ${PREFIX}/share/doc/ddd
	${GZIP_CMD} ${PREFIX}/share/doc/ddd/ddd-paper.ps
	${GZIP_CMD} ${PREFIX}/share/doc/ddd/ddd.ps

.include "../../devel/binutils/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
