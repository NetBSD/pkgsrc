# $NetBSD: Makefile,v 1.5 2003/02/11 04:23:15 jlam Exp $

DISTNAME=	j2sdk-1_4_1_01-linux-i586
PKGNAME=	sun-jdk14-1.0.1
WRKSRC=		${WRKDIR}/j2sdk1.4.1_01
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) 2 SDK, Standard Edition 1.4.1

DEPENDS=	sun-jre14>=1.0.1:../../lang/sun-jre14

# Remove parts that are in common with the JRE
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
	${ECHO} "======================================================================"

.include "../../lang/sun-jre14/Makefile.common"

PREFIX=		${JVM_HOME}
