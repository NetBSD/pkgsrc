# $NetBSD: Makefile,v 1.1 2006/05/15 19:44:07 tv Exp $

DISTNAME=	jdk-${DIST_VER}-${DIST_ARCH}
PKGNAME=	scsl-jdk15-${PKG_VER}
MASTER_SITES=	# empty

SHORT_NAME=	JDK

DEPENDS+=	${PKGNAME_NOREV:S/jdk/jre/:C/p.*$/p/}*:../../lang/scsl-jre15

WRKSRC=		${WRKDIR}/${DISTNAME:S/-//:S/_/./g:C/-.*$//}
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

.include "../../lang/scsl-jre15/Makefile.common"
