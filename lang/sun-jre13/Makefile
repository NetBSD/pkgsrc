# $NetBSD: Makefile,v 1.28 2003/05/02 08:42:05 abs Exp $

DISTNAME=	j2re-1_3_1_08-linux-i586
PKGNAME=	sun-jre13-1.0.8
PKGREVISION=	1
WRKSRC=		${WRKDIR}/jre1.3.1_08
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) Runtime Environment 1.3.1

USE_PKGINSTALL=	yes
OWN_DIRS=	${PREFIX}
OWN_DIRS+=	${PREFIX}/lib
OWN_DIRS+=	${PREFIX}/lib/images
OWN_DIRS+=	${PREFIX}/lib/images/cursors
OWN_DIRS+=	${PREFIX}/lib/security
SFILES=		content-types.properties	flavormap.properties
SFILES+=	font.properties		font.properties.ja
SFILES+=	font.properties.zh	images/cursors/cursors.properties
SFILES+=	jvm.cfg			psfont.properties.ja
SFILES+=	psfontj2d.properties	security/java.security
SUPPORT_FILES=	# empty
.for FILE in ${SFILES}
SUPPORT_FILES+=	${PREFIX}/lib/${FILE}.default ${PREFIX}/lib/${FILE}
.endfor

do-configure:
	cd ${WRKSRC}/lib; for file in ${SFILES}; do			\
		${MV} -f $$file $$file.default;				\
	done

_FETCH_MESSAGE= \
	${ECHO} "======================================================================"; \
	${ECHO} ; \
	${ECHO} " The file ${DISTNAME}${EXTRACT_SUFX} containing the"; \
	${ECHO} " Java(tm) 2 Runtime Environment, Standard Edition must be fetched"; \
	${ECHO} " into:"; \
	${ECHO} "	${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}"; \
	${ECHO} " from:"; \
	${ECHO} "	${DOWNLOAD}"; \
	${ECHO} ; \
	${ECHO} " Choose 'Linux self-extracting file' from the 'JRE' column."; \
	${ECHO} ; \
	${ECHO} "======================================================================"

.include "../../lang/sun-jre13/Makefile.common"

PREFIX=		${JVM_HOME}
