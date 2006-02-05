# $NetBSD: Makefile,v 1.39 2006/02/05 23:09:52 joerg Exp $

DISTNAME=	j2sdk-1_3_1_17-linux-i586
PKGNAME=	sun-jdk13-1.0.17
PKGREVISION=	1
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) Development Kit 1.3.1

SHORT=		JDK

DEPENDS+=	sun-jre13>=1.0.17:../../lang/sun-jre13

JAVA_CLASSPATH=	${JAVA_HOME}/src.jar
JAVA_WRAPPERS=	appletviewer extcheck idlj jar jarsigner \
		javac javadoc javah javap jdb rmic serialver
WRKSRC=		${WRKDIR}/jdk1.3.1_17

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
