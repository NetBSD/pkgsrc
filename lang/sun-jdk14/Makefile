# $NetBSD: Makefile,v 1.17 2004/03/17 22:01:43 jschauma Exp $

DISTNAME=	j2sdk-1_4_2_04-linux-i586
PKGNAME=	sun-jdk14-2.4
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) 2 SDK, Standard Edition 1.4.2

SHORT=		SDK

DEPENDS=	sun-jre14>=2.4:../../lang/sun-jre14

WRKSRC=		${WRKDIR}/j2sdk1.4.2_04

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

.include "../../lang/sun-jre14/Makefile.common"

PREFIX=		${JVM_HOME}
