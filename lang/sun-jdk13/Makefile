# $NetBSD: Makefile,v 1.30 2004/10/05 22:09:23 tv Exp $

DISTNAME=	j2sdk-1_3_1_12-linux-i586
PKGNAME=	sun-jdk13-1.0.12
PKGREVISION=	1
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) Development Kit 1.3.1

SHORT=		JDK

DEPENDS=	sun-jre13>=1.0.12:../../lang/sun-jre13

JAVA_CLASSPATH=	${JAVA_HOME}/src.jar
JAVA_WRAPPERS=	appletviewer extcheck idlj jar jarsigner \
		javac javadoc javah javap jdb rmic serialver
WRKSRC=		${WRKDIR}/jdk1.3.1_12

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
