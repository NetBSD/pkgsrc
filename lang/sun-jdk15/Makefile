# $NetBSD: Makefile,v 1.1.1.1 2004/09/30 23:47:19 rh Exp $

DISTNAME=	jdk-1_5_0-linux-i586
PKGNAME=	sun-jdk15-5.0
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) 2 SDK, Standard Edition 1.5.0

SHORT=		SDK

DEPENDS=	sun-jre15>=5.0:../../lang/sun-jre15

WRKSRC=		${WRKDIR}/jdk1.5.0
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

.include "../../lang/sun-jre15/Makefile.common"
