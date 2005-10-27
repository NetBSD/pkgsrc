# $NetBSD: Makefile,v 1.12 2005/10/27 22:57:27 tv Exp $

DISTNAME=	jdk-1_5_0_05-linux-i586
PKGNAME=	sun-jdk15-5.0.5
PKGREVISION=	1
MASTER_SITES=	# empty

SHORT_NAME=	JDK

DEPENDS=	${PKGNAME_NOREV:S/jdk/jre/}*:../../lang/sun-jre15

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
