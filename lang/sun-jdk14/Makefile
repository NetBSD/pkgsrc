# $NetBSD: Makefile,v 1.19 2004/07/02 14:40:21 jschauma Exp $

DISTNAME=	j2sdk-1_4_2_05-linux-i586
PKGNAME=	sun-jdk14-2.5
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) 2 SDK, Standard Edition 1.4.2

SHORT=		SDK

DEPENDS=	sun-jre14>=2.5:../../lang/sun-jre14

WRKSRC=		${WRKDIR}/j2sdk1.4.2_05
JAVA_WRAPPERS=	appletviewer jar javac javadoc javah javap

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
