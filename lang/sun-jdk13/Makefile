# $NetBSD: Makefile,v 1.17 2003/01/29 11:10:19 jlam Exp $

DISTNAME=	j2sdk-1_3_1_07-linux-i586
PKGNAME=	sun-jdk13-1.0.7
WRKSRC=		${WRKDIR}/jdk1.3.1_07
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) Development Kit 1.3.1

DEPENDS=	sun-jre13>=1.0.7:../../lang/sun-jre13

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
	${ECHO} "======================================================================"

.include "../../lang/sun-jre13/Makefile.common"

PREFIX=		${JVM_HOME}
