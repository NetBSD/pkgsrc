# $NetBSD: Makefile,v 1.2 2006/06/18 08:51:10 rillig Exp $

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
	set -e;								\
	cd ${WRKSRC};							\
	common=`${AWK} '/^#.*/ { next } /^$$/ { next } { print }' ${FILESDIR}/common`; \
	for i in $$common; do						\
		if [ -d "$$i" ]; then					\
			${RM} -rf "$$i";				\
		else							\
			${RM} -f "$$i";					\
		fi;							\
	done
	${RM} -f ${WRKSRC}/jre
	${LN} -s . ${WRKSRC}/jre

.include "../../lang/scsl-jre15/Makefile.common"
