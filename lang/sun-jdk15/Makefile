# $NetBSD: Makefile,v 1.34 2009/07/23 17:18:43 abs Exp $

DISTNAME=	jdk-1_5_0_19-linux-${DIST_ARCH}
PKGNAME=	sun-jdk15-5.0.19
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
