# $NetBSD: Makefile,v 1.22 2003/05/02 08:42:05 abs Exp $

DISTNAME=	j2sdk-1_3_1_08-linux-i586
PKGNAME=	sun-jdk13-1.0.8
PKGREVISION=	1
WRKSRC=		${WRKDIR}/jdk1.3.1_08
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) Development Kit 1.3.1

DEPENDS=	sun-jre13>=1.0.8nb1:../../lang/sun-jre13

# Remove parts that are in common with the JRE.
#
post-extract:
	common=`${AWK} '/^#.*/ { next } /^$$/ { next } { print }' ${FILESDIR}/common`; \
	cd ${WRKSRC}; for i in $$common; do				\
		if [ -d $$i ]; then					\
			${RM} -rf $$i;					\
		else							\
			${RM} -f $$i;					\
		fi;							\
	done
	${LN} -sf . ${WRKSRC}/jre

_FETCH_MESSAGE= \
	${ECHO} "======================================================================"; \
	${ECHO} ; \
	${ECHO} " The file ${DISTNAME}${EXTRACT_SUFX} containing the"; \
	${ECHO} " Java(tm) 2 SDK, Standard Edition must be fetched"; \
	${ECHO} " into:"; \
	${ECHO} "	${DISTDIR}"; \
	${ECHO} " from:"; \
	${ECHO} "	${DOWNLOAD}"; \
	${ECHO} ; \
	${ECHO} " Choose 'Linux self-extracting file' from the 'SDK' column."; \
	${ECHO} ; \
	${ECHO} "======================================================================"

.include "../../lang/sun-jre13/Makefile.common"

PREFIX=		${JVM_HOME}
