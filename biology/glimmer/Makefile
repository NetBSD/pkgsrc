# $NetBSD: Makefile,v 1.2 2003/10/07 18:20:15 jschauma Exp $
#

DISTNAME=		glimmer212
PKGNAME=		glimmer-2.12
WRKSRC=                 ${WRKDIR}/glimmer2.12
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.tigr.org/pub/software/Glimmer/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		ftp://ftp.tigr.org/pub/software/Glimmer/
COMMENT=		System for finding genes in microbial DNA

USE_BUILDLINK2=		yes

do-install:
.for PROGRAM in adjust anomaly build-icm check codon-usage compare-lists \
	generate get-len get-putative glimmer2 long-orfs
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${PREFIX}/bin
.endfor
	# ``extract'' is also in the csound package, so rename to avoid conflict
	${INSTALL_PROGRAM} ${WRKSRC}/extract ${PREFIX}/bin/glextract
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/glimmer
	${CP} ${WRKSRC}/README ${WRKSRC}/run-glimmer2.readme
.for DOC in run-glimmer2.readme build-icm.readme extract.readme glimmer2.readme long-orfs.readme
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${PREFIX}/share/doc/glimmer
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/glimmer
	${INSTALL_SCRIPT} ${WRKSRC}/run-glimmer2 ${PREFIX}/share/glimmer

.include "../../mk/bsd.pkg.mk"
