# $NetBSD: Makefile,v 1.1 2007/02/18 19:11:26 tv Exp $

DISTNAME=	jdk-6-linux-i586
PKGNAME=	sun-jdk6-6.0
MASTER_SITES=	# empty

SHORT_NAME=	JDK

DEPENDS+=	${PKGNAME_NOREV:S/jdk/jre/}*:../../lang/sun-jre6

CHECK_SHLIBS=	no	# One of the demos is broken.
WRKSRC=		${WRKDIR}/jdk1.6.0
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

.include "../../lang/sun-jre6/Makefile.common"
