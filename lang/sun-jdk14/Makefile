# $NetBSD: Makefile,v 1.15 2003/12/12 17:17:19 jschauma Exp $

DISTNAME=	j2sdk-1_4_2_03-linux-i586
PKGNAME=	sun-jdk14-2.3
WRKSRC=		${WRKDIR}/j2sdk1.4.2_03
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) 2 SDK, Standard Edition 1.4.2

SHORT=		SDK

DEPENDS=	sun-jre14>=2.0:../../lang/sun-jre14

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
