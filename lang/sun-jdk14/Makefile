# $NetBSD: Makefile,v 1.37 2007/08/22 14:03:47 jlam Exp $

DISTNAME=	j2sdk-1_4_2_14-linux-${DIST_ARCH}
PKGNAME=	sun-jdk14-2.14
PKGREVISION=	1
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) 2 SDK, Standard Edition 1.4.2

SHORT=		SDK

DEPENDS+=	sun-jre14>=2.9:../../lang/sun-jre14

WRKSRC=		${WRKDIR}/j2sdk1.4.2_14
JAVA_WRAPPERS+=	appletviewer extcheck idlj jar jarsigner \
		javac javadoc javah javap jdb rmic serialver

.include "../../lang/sun-jre14/Makefile.common"

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
