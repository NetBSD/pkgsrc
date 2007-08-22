# $NetBSD: Makefile,v 1.42 2007/08/22 14:03:47 jlam Exp $

DISTNAME=	j2sdk-1_3_1_19-linux-${DIST_ARCH}
PKGNAME=	sun-jdk13-1.0.19
PKGREVISION=	1
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) Development Kit 1.3.1

SHORT=		JDK

DEPENDS+=	sun-jre13>=1.0.19:../../lang/sun-jre13

WRKSRC=		${WRKDIR}/jdk1.3.1_19
JAVA_CLASSPATH=	${JAVA_HOME}/src.jar
JAVA_WRAPPERS=	appletviewer extcheck idlj jar jarsigner \
		javac javadoc javah javap jdb rmic serialver

.include "../../lang/sun-jre13/Makefile.common"

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

.include "../../mk/bsd.pkg.mk"
