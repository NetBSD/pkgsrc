# $NetBSD: Makefile,v 1.5 2007/08/22 14:03:48 jlam Exp $

DISTNAME=	jdk-6u1-linux-${DIST_ARCH}
PKGNAME=	sun-jdk6-6.0.1
PKGREVISION=	1
MASTER_SITES=	# empty

DOWNLOAD_NAME=	JDK 6u1
SHORT_NAME=	JDK

DEPENDS+=	${PKGNAME_NOREV:S/jdk/jre/}*:../../lang/sun-jre6

WRKSRC=		${WRKDIR}/jdk1.6.0_01
JAVA_WRAPPERS=	appletviewer apt extcheck idlj jar jarsigner \
		javac javadoc javah javap jdb rmic serialver

.include "../../lang/sun-jre6/Makefile.common"

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

.include "../../mk/bsd.pkg.mk"
