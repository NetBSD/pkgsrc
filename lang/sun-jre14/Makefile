# $NetBSD: Makefile,v 1.12 2003/12/12 15:16:49 adam Exp $

DISTNAME=	j2re-1_4_2_03-linux-i586
PKGNAME=	sun-jre14-2.3
WRKSRC=		${WRKDIR}/j2re1.4.2_03
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) 2 Runtime Environment 1.4.2

USE_PKGINSTALL=	yes
OWN_DIRS=	${PREFIX}
OWN_DIRS+=	${PREFIX}/lib
OWN_DIRS+=	${PREFIX}/lib/applet
OWN_DIRS+=	${PREFIX}/lib/images
OWN_DIRS+=	${PREFIX}/lib/images/cursors
OWN_DIRS+=	${PREFIX}/lib/security
SFILES=		content-types.properties	flavormap.properties
SFILES+=	font.properties			font.properties.Redhat6.1
SFILES+=	font.properties.ja		font.properties.ja.Redhat6.1
SFILES+=	font.properties.ja.Redhat6.2	font.properties.ja.Turbo
SFILES+=	font.properties.ja.Turbo6.0	font.properties.zh.Turbo
SFILES+=	images/cursors/cursors.properties	i386/jvm.cfg
SFILES+=	logging.properties		psfont.properties.ja
SFILES+=	psfontj2d.properties		security/java.security
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

.include "../../lang/sun-jre14/Makefile.common"

PREFIX=		${JVM_HOME}
