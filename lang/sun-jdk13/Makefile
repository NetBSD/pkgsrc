# $NetBSD: Makefile,v 1.27 2004/05/22 20:20:06 jmmv Exp $

DISTNAME=	j2sdk-1_3_1_11-linux-i586
PKGNAME=	sun-jdk13-1.0.11
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) Development Kit 1.3.1

SHORT=		JDK

DEPENDS=	sun-jre13>=1.0.11:../../lang/sun-jre13

WRKSRC=		${WRKDIR}/jdk1.3.1_11

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
