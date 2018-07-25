# $NetBSD: Makefile,v 1.1 2018/07/25 15:14:32 bacon Exp $

DISTNAME=	Trimmomatic-${PV}
CATEGORIES=	biology
MASTER_SITES=	http://www.usadellab.org/cms/uploads/supplementary/Trimmomatic/
EXTRACT_SUFX=	.zip

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://www.usadellab.org/cms/?page=trimmomatic
COMMENT=	Flexible read trimming tool for Illumina NGS data
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pax
USE_JAVA=	run
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Trimmomatic-${PV}

INSTALLATION_DIRS=	lib/java share/trimmomatic

PV=		0.38

do-install:
	${INSTALL_DATA} ${WRKSRC}/trimmomatic-${PV}.jar \
		${DESTDIR}${PREFIX}/lib/java/trimmomatic.jar
	cd ${WRKSRC} && pax -rw adapters ${DESTDIR}${PREFIX}/share/trimmomatic

.include "../../mk/bsd.pkg.mk"
