# $NetBSD: Makefile,v 1.3 2022/06/28 11:31:00 wiz Exp $

DISTNAME=	fastqc_v${PKGVERSION_NOREV}
PKGNAME=	fastqc-0.11.9
PKGREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	https://www.bioinformatics.babraham.ac.uk/projects/fastqc/
EXTRACT_SUFX=	.zip

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://www.bioinformatics.babraham.ac.uk/projects/fastqc/
COMMENT=	Quality control tool for high throughput sequence data
LICENSE=	gnu-gpl-v3

SUBST_CLASSES+=		javapath
SUBST_STAGE.javapath=	pre-configure
SUBST_SED.javapath+=	-e 's|$$RealBin$$delimiter|${DATADIR}$$delimiter${JAVAJARDIR}/fastqc$$delimiter|g'
SUBST_SED.javapath+=	-e 's|$$RealBin/|${JAVAJARDIR}/fastqc/|g'
SUBST_FILES.javapath+=	fastqc

USE_TOOLS+=	perl:run pax
USE_JAVA=	run
USE_JAVA2=	8

WRKSRC=		${WRKDIR}/FastQC
REPLACE_PERL=	fastqc
NO_BUILD=	yes

DATADIR=	${PREFIX}/share/fastqc
DOCSDIR=	${PREFIX}/share/doc/fastqc
JAVAJARDIR=	${PREFIX}/share/java/classes

INSTALLATION_DIRS=	bin ${DATADIR} ${DOCSDIR} ${JAVAJARDIR}/fastqc

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.jar ${DESTDIR}${JAVAJARDIR}/fastqc
	${INSTALL_SCRIPT} ${WRKSRC}/fastqc ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && pax -rw Configuration ${DESTDIR}${DATADIR}
	cd ${WRKSRC} && pax -rw Templates ${DESTDIR}${DATADIR}
	cd ${WRKSRC} && pax -rw net ${DESTDIR}${JAVAJARDIR}/fastqc
	cd ${WRKSRC} && pax -rw org ${DESTDIR}${JAVAJARDIR}/fastqc
	cd ${WRKSRC} && pax -rw uk ${DESTDIR}${JAVAJARDIR}/fastqc
	cd ${WRKSRC} && pax -rw Help ${DESTDIR}${DOCSDIR}

.include "../../mk/bsd.pkg.mk"
