# $NetBSD: Makefile,v 1.16 1998/12/07 11:37:51 frueauf Exp $
# $FreeBSD Id: Makefile,v 1.5 1998/02/19 09:43:16 obrien Exp
#

DISTNAME=	ddd-3.1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ips.cs.tu-bs.de/pub/local/softech/ddd/  \
		ftp://richb-pc.acc.qc.edu/pub/ddd/  \
		ftp://ftp.gre.ac.uk/pub/tools/debuggers/ddd/  \
		ftp://uiarchive.cso.uiuc.edu/pub/packages/ddd/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://www.cs.tu-bs.de/softech/ddd/

DEPENDS+=	xpm-3.4k:../../graphics/xpm

CONFLICTS=	ddd-2.2.3 ddd-3.1

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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/PROBLEMS ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/README ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/ddd-paper.ps ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/ddd.man.ps ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/sample.dddinit ${PREFIX}/share/doc/ddd
	${GZIP_CMD} ${PREFIX}/share/doc/ddd/ddd-paper.ps
	${GZIP_CMD} ${PREFIX}/share/doc/ddd/ddd.man.ps
.endif

check:
	(cd ${WRKSRC} ; ${GMAKE} check)

.include "../../mk/bsd.pkg.mk"
