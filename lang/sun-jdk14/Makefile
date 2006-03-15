# $NetBSD: Makefile,v 1.28.2.1 2006/03/15 13:27:25 salo Exp $

DISTNAME=	j2sdk-1_4_2_11-linux-i586
PKGNAME=	sun-jdk14-2.11
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) 2 SDK, Standard Edition 1.4.2

SHORT=		SDK

DEPENDS+=	sun-jre14>=2.9:../../lang/sun-jre14

WRKSRC=		${WRKDIR}/j2sdk1.4.2_11
JAVA_WRAPPERS+=	appletviewer extcheck idlj jar jarsigner \
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

.include "../../lang/sun-jre14/Makefile.common"
