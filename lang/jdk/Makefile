# $NetBSD: Makefile,v 1.19 2000/11/18 00:40:50 tv Exp $
#
.include "../../mk/bsd.prefs.mk"

VERSION=1.1.8
PKGNAME=	jdk-${VERSION}
CATEGORIES=     lang
MASTER_SITES=   ftp://ftp.netbsd.org/pub/NetBSD/misc/java/i386/${VERSION}/ \
		ftp://ftp.de.netbsd.org/pub/NetBSD/misc/java/i386/${VERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=     jwise@netbsd.org
HOMEPAGE=       http://www.quick.com.au/java/

CONFLICTS=	blackdown-j* sun-j*

.include "../../mk/bsd.prefs.mk"
.if !defined(JDK_HOME)
JDK_HOME:=	${LOCALBASE}/java
.endif

.if ${OBJECT_FMT} == "ELF"
DISTNAME=	jdk${VERSION}-rc1-elf
WRKSRC=		${WRKDIR}/jdk${VERSION}-elf
PLIST_SRC=	${PKGDIR}/PLIST-elf
.else
DISTNAME=       jdk${VERSION}-rc1
WRKSRC=		${WRKDIR}/jdk${VERSION}
PLIST_SRC=	${PKGDIR}/PLIST-aout
.endif
PLIST_SRC+=	${PKGDIR}/PLIST

CHECK_SHLIBS=	no
NO_BUILD=	yes
# since we change PREFIX:
NO_MTREE=	yes
MESSAGE_FILE=	${WRKDIR}/.MESSAGE

ONLY_FOR_PLATFORM= NetBSD-*-i386
RESTRICTED=	"No redistribution of the Java(tm) Development Kit"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

.if ${OBJECT_FMT} == "ELF"
# This gross hack normalizes the shlib names so that automatic
# shared library handling will work.
pre-install:
	@for X in ${WRKSRC}/lib/i386/green_threads/lib*.so ;do \
		if [ -f $$X.* ] ;then \
			${MV} $$X $$X.* ;\
		elif [ -f "$$X" ] ;then \
			${MV} $$X $$X.${VERSION} ;\
		fi ;\
	done
.endif

do-install:
	${RM} -f ${WRKSRC}/*.orig
	${MKDIR} ${JDK_HOME}
	cd ${WRKSRC} ; ${GTAR} pcf - . | ( cd ${JDK_HOME} ; ${GTAR} pvxf - )
	${SED} \
		-e 's|@JDK_HOME@|${JDK_HOME}|g' \
		<${PKGDIR}/MESSAGE >${MESSAGE_FILE}

.include "../../mk/bsd.pkg.mk"

# This needs to be after bsd.pkg.mk 
PREFIX:=	${JDK_HOME}
