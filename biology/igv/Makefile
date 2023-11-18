# $NetBSD: Makefile,v 1.2 2023/11/18 15:03:23 abs Exp $

DISTNAME=	IGV_2.9.2
PKGNAME=	${DISTNAME:S/IGV_/igv-/}
CATEGORIES=	biology
MASTER_SITES=	https://data.broadinstitute.org/igv/projects/downloads/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.zip

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://software.broadinstitute.org/software/igv/
COMMENT=	Visualization tool for genomic datasets
LICENSE=	mit

USE_JAVA=	yes
USE_JAVA2=	11
USE_TOOLS+=	pax
NO_BUILD=	yes

SUBST_CLASSES+=		java
SUBST_STAGE.java=	pre-configure
SUBST_SED.java=		-e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g'
SUBST_SED.java+=	-e 's|%%PREFIX%%|${PREFIX}|g'
SUBST_FILES.java=	igv

JAVAJARDIR=		${PREFIX}/share/java/classes
INSTALLATION_DIRS=	bin ${JAVAJARDIR}/igv

pre-patch:
	${CP} ${FILESDIR}/igv.sh.in ${WRKSRC}/igv

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/igv ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${DESTDIR}${JAVAJARDIR}/igv
	${INSTALL_DATA} ${WRKSRC}/igv.args ${DESTDIR}${JAVAJARDIR}/igv
	cd ${WRKSRC}/lib && pax -rw genomes ${DESTDIR}${JAVAJARDIR}/igv

.include "../../mk/bsd.pkg.mk"
