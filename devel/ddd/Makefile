# $NetBSD: Makefile,v 1.25 2000/03/11 17:17:12 fredb Exp $
# $FreeBSD Id: Makefile,v 1.5 1998/02/19 09:43:16 obrien Exp
#

DISTNAME=	ddd-3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=ddd/}

MAINTAINER=     frueauf@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/ddd/

BUILD_DEPENDS+=	bison:../../devel/bison
DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_MOTIF=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

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
	@${MKDIR} ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/PROBLEMS ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/README ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/ddd-paper.ps ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/ddd.ps ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/ddd.pdf ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/sample.dddinit ${PREFIX}/share/doc/ddd
	${GZIP_CMD} ${PREFIX}/share/doc/ddd/ddd-paper.ps
	${GZIP_CMD} ${PREFIX}/share/doc/ddd/ddd.ps

check:
	(cd ${WRKSRC} ; ${GMAKE} check)

.include "../../mk/bsd.pkg.mk"
