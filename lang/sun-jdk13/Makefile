# $NetBSD: Makefile,v 1.23 2003/08/12 16:37:04 jschauma Exp $

DISTNAME=	j2sdk-1_3_1_09-linux-i586
PKGNAME=	sun-jdk13-1.0.9
WRKSRC=		${WRKDIR}/jdk1.3.1_09
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) Development Kit 1.3.1

DEPENDS=	sun-jre13>=1.0.9:../../lang/sun-jre13

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
