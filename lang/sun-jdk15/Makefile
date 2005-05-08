# $NetBSD: Makefile,v 1.7 2005/05/08 16:13:46 abs Exp $

DISTNAME=	jdk-1_5_0_03-linux-i586
PKGNAME=	sun-jdk15-5.0.3
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) 2 SDK, Standard Edition 1.5.0

SHORT=		SDK

DEPENDS=	sun-jre15-5.0.3*:../../lang/sun-jre15

WRKSRC=		${WRKDIR}/jdk1.5.0_03
JAVA_WRAPPERS=	appletviewer apt extcheck idlj jar jarsigner \
		javac javadoc javah javap jdb rmic serialver

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
