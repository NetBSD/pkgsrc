# $NetBSD: Makefile,v 1.7 2008/01/20 09:21:35 tnn Exp $

DISTNAME=	jdk-6u4-linux-${DIST_ARCH}
PKGNAME=	sun-jdk6-6.0.4
MASTER_SITES=	# empty

DOWNLOAD_NAME=	JDK 6u4
SHORT_NAME=	JDK

DEPENDS+=	${PKGNAME_NOREV:S/jdk/jre/}*:../../lang/sun-jre6

WRKSRC=		${WRKDIR}/jdk1.6.0_04
JAVA_WRAPPERS=	appletviewer apt extcheck idlj jar jarsigner \
		javac javadoc javah javap jdb rmic serialver

LICENSE=	sun-jdk6-license

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
