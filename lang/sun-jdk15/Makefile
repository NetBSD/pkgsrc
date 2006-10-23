# $NetBSD: Makefile,v 1.22 2006/10/23 19:38:15 tv Exp $

DISTNAME=	jdk-1_5_0_09-linux-i586
PKGNAME=	sun-jdk15-5.0.9
PKGREVISION=	1
MASTER_SITES=	# empty

SHORT_NAME=	JDK

DEPENDS+=	${PKGNAME_NOREV:S/jdk/jre/}*:../../lang/sun-jre15

CHECK_SHLIBS=	no	# One of the demos is broken.
WRKSRC=		${WRKDIR}/${DISTNAME:S/-//:S/_/./:S/_/./:S/-linux-i586//}
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
