# $NetBSD: Makefile,v 1.25 2004/01/02 17:07:21 jschauma Exp $

DISTNAME=	j2sdk-1_3_1_10-linux-i586
PKGNAME=	sun-jdk13-1.0.10
WRKSRC=		${WRKDIR}/jdk1.3.1_10
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) Development Kit 1.3.1

SHORT=		JDK

DEPENDS=	sun-jre13>=1.0.10:../../lang/sun-jre13

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

.include "../../lang/sun-jre13/Makefile.common"

PREFIX=		${JVM_HOME}
