# $NetBSD: Makefile,v 1.18 2004/05/22 21:32:34 jmmv Exp $

DISTNAME=	j2sdk-1_4_2_04-linux-i586
PKGNAME=	sun-jdk14-2.4
PKGREVISION=	1
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) 2 SDK, Standard Edition 1.4.2

SHORT=		SDK

DEPENDS=	sun-jre14>=2.4nb1:../../lang/sun-jre14

WRKSRC=		${WRKDIR}/j2sdk1.4.2_04
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
