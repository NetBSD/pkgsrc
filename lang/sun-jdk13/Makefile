# $NetBSD: Makefile,v 1.24 2004/01/02 16:56:01 jschauma Exp $

DISTNAME=	j2sdk-1_3_1_09-linux-i586
PKGNAME=	sun-jdk13-1.0.9
WRKSRC=		${WRKDIR}/jdk1.3.1_09
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) Development Kit 1.3.1

SHORT=		JDK

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

.include "../../lang/sun-jre13/Makefile.common"

PREFIX=		${JVM_HOME}
