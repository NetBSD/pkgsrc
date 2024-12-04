# $NetBSD: Makefile,v 1.1 2024/12/04 13:38:32 bacon Exp $

DISTNAME=	FastTree-2.1.11
CATEGORIES=	biology
MASTER_SITES=	http://www.microbesonline.org/fasttree/
EXTRACT_SUFX=	.c

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://www.microbesonline.org/fasttree/
COMMENT=	Approximately-maximum-likelihood phylogenetic trees from alignments
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}

.include "../../mk/bsd.prefs.mk"

# Xcode supports -Xpreprocessor -fopenmp, but does not supply OpenMP libs
.if ${OPSYS} == Darwin
SUBST_CLASSES+=		openmp
SUBST_SED.openmp=	-e 's|-fopenmp|-Xpreprocessor &|g'
SUBST_STAGE.openmp=	pre-configure
SUBST_FILES.openmp=	Makefile
LDFLAGS+= 		-L${PREFIX}/lib -lomp -lm
.include "../../parallel/openmp/buildlink3.mk"
.endif

do-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
