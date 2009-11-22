# $NetBSD: Makefile,v 1.36 2009/11/22 19:48:06 abs Exp $

DISTNAME=	jdk-1_5_0_22-linux-${DIST_ARCH}
PKGNAME=	sun-jdk15-5.0.22
MASTER_SITES=	# empty

LICENSE=	sun-jdk6-license

SHORT_NAME=	JDK

DEPENDS+=	${PKGNAME_NOREV:S/jdk/jre/}*:../../lang/sun-jre15

USE_TOOLS+=	gawk
WRKSRC=		${WRKDIR}/${DISTNAME:S/-//:S/_/./:S/_/./:C/-linux-.*//}
JAVA_WRAPPERS=	appletviewer apt extcheck idlj jar jarsigner \
		javac javadoc javah javap jdb rmic serialver

.include "../../lang/sun-jre15/Makefile.common"

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
