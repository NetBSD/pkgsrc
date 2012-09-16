# $NetBSD: Makefile,v 1.12 2012/09/16 17:20:17 cheusov Exp $
#

DISTNAME=		glimmer213
PKGREVISION=		1
PKGNAME=		glimmer-2.13
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.tigr.org/pub/software/Glimmer/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		ftp://ftp.tigr.org/pub/software/Glimmer/
COMMENT=		System for finding genes in microbial DNA

CONFLICTS+=		generate-[0-9]*

USE_LANGUAGES=		c c++

WRKSRC=			${WRKDIR}/glimmer2.13
INSTALLATION_DIRS=	bin

do-install:
.for PROGRAM in adjust anomaly build-icm check codon-usage compare-lists \
	generate get-len get-putative glimmer2 long-orfs
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${DESTDIR}${PREFIX}/bin
.endfor
	# ``extract'' is also in the csound package, so rename to avoid conflict
	${INSTALL_PROGRAM} ${WRKSRC}/extract ${DESTDIR}${PREFIX}/bin/glextract
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/glimmer
	${CP} ${WRKSRC}/README ${WRKSRC}/run-glimmer2.readme
.for DOC in run-glimmer2.readme build-icm.readme extract.readme glimmer2.readme long-orfs.readme
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${DESTDIR}${PREFIX}/share/doc/glimmer
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/glimmer
	${INSTALL_SCRIPT} ${WRKSRC}/run-glimmer2 ${DESTDIR}${PREFIX}/share/glimmer

.include "../../mk/bsd.pkg.mk"
