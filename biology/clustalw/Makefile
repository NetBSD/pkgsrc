# $NetBSD: Makefile,v 1.12 2012/09/11 20:32:11 asau Exp $

DISTNAME=	clustalw1.83.UNIX
PKGNAME=	clustalw-1.83
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp-igbmc.u-strasbg.fr/pub/ClustalW/ \
		ftp://ftp.ebi.ac.uk/pub/software/unix/clustalw/

MAINTAINER=	babafou@babafou.eu.org
HOMEPAGE=	http://bips.u-strasbg.fr/fr/Documentation/ClustalW/
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
	${INSTALL_PROGRAM} ${WRKSRC}/clustalw ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/clustalw
	for f in clustalv.doc clustalw.doc clustalw.ms clustalw_help; do \
		${INSTALL_DATA} ${WRKSRC}/$$f \
			${DESTDIR}${PREFIX}/share/doc/clustalw; \
	done

.include "../../mk/bsd.pkg.mk"
