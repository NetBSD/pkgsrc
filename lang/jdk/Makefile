# $NetBSD: Makefile,v 1.10 1999/12/10 03:55:22 hubertf Exp $
#

VERSION=1.1.6
DISTNAME=       jdk${VERSION}
PKGNAME=	jdk-${VERSION}
CATEGORIES=     lang
MASTER_SITES=   ftp://ftp.netbsd.org/pub/NetBSD/misc/java/i386/${VERSION}/ \
		ftp://ftp.de.netbsd.org/pub/NetBSD/misc/java/i386/${VERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=     packages@netbsd.org
HOMEPAGE=       http://www.quick.com.au/java/

.include "../../mk/bsd.prefs.mk"
.if !defined(JDK_HOME)
JDK_HOME:=	${LOCALBASE}/java
.endif

WRKSRC=		${WRKDIR}/jdk${VERSION}
NO_BUILD=	yes
MESSAGE_FILE=	${WRKDIR}/.MESSAGE

ONLY_FOR_PLATFORM= NetBSD-*-i386
RESTRICTED=	"No redistribution of the Java(tm) Development Kit"
NO_CDROM=	${RESTRICTED}

do-install:
	${RM} ${WRKSRC}/README.NetBSD.orig
	${MKDIR} ${JDK_HOME}
	cd ${WRKSRC} ; ${GTAR} pcf - . | ( cd ${JDK_HOME} ; ${GTAR} pvxf - )
	${SED} \
		-e 's|@JDK_HOME@|${JDK_HOME}|g' \
		<${PKGDIR}/MESSAGE >${MESSAGE_FILE}


.include "../../mk/bsd.pkg.mk"


# This needs to be after bsd.pkg.mk 
PREFIX:=	${JDK_HOME}
