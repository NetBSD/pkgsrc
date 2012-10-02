# $NetBSD: Makefile,v 1.6 2012/10/02 20:11:47 asau Exp $
#

DISTNAME=	jdk1.7.0-20090502-${MACHINE_ARCH}-NetBSD_5.0
PKGNAME=	${DISTNAME:C:-${MACHINE_ARCH}.*:::C:[^-]*-:openjdk7-bin-:}
CATEGORIES=	lang
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/java/openjdk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openjdk.java.net/projects/bsd-port/
COMMENT=	Binary OpenJDK package

JAVA_NAME=	openjdk7-bin
JAVA_HOME=	${PREFIX}/java/${JAVA_NAME}
JAVA_WRAPPERS=	jar java javac javadoc javah javap keytool orbd \
		policytool rmid rmiregistry servertool tnameserv

WRKSRC=		${WRKDIR}/openjdk7-j2sdk
USE_LANGUAGES=	# none
USE_TOOLS+=	pax
CHECK_SHLIBS_SUPPORTED= NO

JAVA_MACHINE_ARCH=${MACHINE_ARCH}
.if ${MACHINE_ARCH} == "i386"
PLIST.client=		yes
.elif ${MACHINE_ARCH} == "x86_64"
JAVA_MACHINE_ARCH=	amd64
.endif
PLIST_SUBST+=	JAVA_MACHINE_ARCH=${JAVA_MACHINE_ARCH:Q}
PLIST_VARS+=	client

ONLY_FOR_PLATFORM=	NetBSD-[5-9]*-i386 NetBSD-[5-9]*-x86_64

INSTALLATION_DIRS=	java/${JAVA_NAME}

do-build:
	# Cannot use NO_BUILD as need java wrappers

do-install:
	cd ${WRKSRC} && ${PAX} -rwp ma . ${DESTDIR}${JAVA_HOME}

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
