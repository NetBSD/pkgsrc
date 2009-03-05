# $NetBSD: Makefile,v 1.1.1.1 2009/03/05 00:25:54 abs Exp $
#

DISTNAME=	jdk1.7.0.20090129-i386-netbsd5
PKGNAME=	${DISTNAME:C:-i386.*:::C:.*\.:openjdk7-bin-:}
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/jmcneill/java/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://openjdk.java.net/projects/bsd-port/
COMMENT=	Binary OpenJDK package

JAVA_NAME=	openjdk7-bin
JAVA_HOME=	${PREFIX}/java/${JAVA_NAME}
JAVA_WRAPPERS=	java javaws keytool orbd policytool rmid rmiregistry \
		servertool tnameserv

WRKSRC=		${WRKDIR}/jdk1.7.0
USE_LANGUAGES=	# none
USE_TOOLS+=	pax
CHECK_SHLIBS_SUPPORTED=	NO

ONLY_FOR_PLATFORM=    NetBSD-[5-9]*-i386

INSTALLATION_DIRS= 	java/${JAVA_NAME}
PKG_DESTDIR_SUPPORT=    user-destdir

do-build:
	# Cannot use NO_BUILD as need java wrappers

do-install:
	cd ${WRKSRC} && ${PAX} -rwp ma . ${DESTDIR}${JAVA_HOME}

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
