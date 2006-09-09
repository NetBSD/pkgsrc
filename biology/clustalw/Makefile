# $NetBSD: Makefile,v 1.9 2006/09/09 02:41:55 obache Exp $

DISTNAME=	clustalw1.83.UNIX
PKGNAME=	clustalw-1.83
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp-igbmc.u-strasbg.fr/pub/ClustalW/ \
		ftp://ftp.ebi.ac.uk/pub/software/unix/clustalw/

MAINTAINER=	babafou@babafou.eu.org
HOMEPAGE=	http://www-igbmc.u-strasbg.fr/BioInfo/ClustalW/
COMMENT=	General purpose multiple alignment program for DNA or proteins

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_FILE=	makefile
BUILD_TARGET=	clustalw
WRKSRC=		${WRKDIR}/clustalw1.83

MAKE_FLAGS+=	CC=${CC:Q}

INSTALLATION_DIRS=	bin

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
