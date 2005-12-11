# $NetBSD: Makefile,v 1.15 2005/12/11 09:22:52 wiz Exp $

DISTNAME=	jdk-1_5_0_06-linux-i586
PKGNAME=	sun-jdk15-5.0.6
MASTER_SITES=	# empty

SHORT_NAME=	JDK

DEPENDS+=	sun-jre15-${PKGVERSION}*:../../lang/sun-jre15

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
