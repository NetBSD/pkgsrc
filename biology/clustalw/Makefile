# $NetBSD: Makefile,v 1.1.1.1 1999/07/28 20:07:00 rh Exp $

DISTNAME=	clustalw1.8.UNIX
PKGNAME=	clustalw-1.8
WRKSRC=		${WRKDIR}/clustalw1.8
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp-igbmc.u-strasbg.fr/pub/ClustalW/ \
		ftp://ftp.ebi.ac.uk/pub/software/unix/clustalw/

MAINTAINER=	babafou@babafou.eu.org
HOMEPAGE=	http://www-igbmc.u-strasbg.fr/BioInfo/ClustalW/

MAKEFILE=	makefile
ALL_TARGET=	clustalw

post-patch:
	@${SED} -e 's:@PREFIX@:${PREFIX}:' < ${WRKSRC}/clustalw.c \
		> ${WRKSRC}/clustalw.c.tmp \
		&& ${MV} ${WRKSRC}/clustalw.c.tmp ${WRKSRC}/clustalw.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clustalw ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/clustalw
	for f in clustalv.doc clustalw.doc clustalw.ms clustalw_help; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/clustalw; \
	done

.include "../../mk/bsd.pkg.mk"
