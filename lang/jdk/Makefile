# $NetBSD: Makefile,v 1.41 2004/10/11 14:07:37 tv Exp $
#

VERSION=	1.1.8
PKGNAME=	jdk-${VERSION}
PKGREVISION=	7
CATEGORIES=	lang java
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/java/i386/${VERSION}/ \
		ftp://ftp.de.NetBSD.org/pub/NetBSD/misc/java/i386/${VERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jwise@NetBSD.org
COMMENT=	Sun's Java(tm) Development Kit

LICENSE=	jdk-license

.include "../../mk/bsd.prefs.mk"

JAVA_HOME=	${PREFIX}/java/jdk-${VERSION}
JAVA_NAME=	jdk11
JAVA_WRAPPERS=	appletviewer jar java javac javadoc javah javakey \
		javap jdb rmic rmiregistry serialver

.if ${OBJECT_FMT} == "ELF"
DISTNAME=	jdk${VERSION}-rc1-elf
WRKSRC=		${WRKDIR}/jdk${VERSION}-elf
PLIST_SRC=	${PKGDIR}/PLIST-elf
.else
DISTNAME=	jdk${VERSION}-rc1
WRKSRC=		${WRKDIR}/jdk${VERSION}
PLIST_SRC=	${PKGDIR}/PLIST-aout
.endif
PLIST_SRC+=	${PKGDIR}/PLIST

MESSAGE_SUBST+=	JAVA_HOME=${JAVA_HOME:Q}

CHECK_SHLIBS=	no

NO_BUILDLINK=	yes
USE_PKGINSTALL=	yes

ONLY_FOR_PLATFORM= NetBSD-*-i386 Linux-*-i[3-6]86
RESTRICTED=	"No redistribution of the Java(tm) Development Kit"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

OWNDIRS+=	${JAVA_HOME} ${JAVA_HOME}/lib ${JAVA_HOME}/lib/security
SFILES=		appletviewer.properties		awt.properties
SFILES+=	content-types.properties	font.properties
SFILES+=	font.properties.ISO8859_15_FDIS	font.properties.cs
SFILES+=	font.properties.el		font.properties.hu
SFILES+=	font.properties.ja		font.properties.ko
SFILES+=	font.properties.lt		font.properties.lv
SFILES+=	font.properties.pl		font.properties.ru
SFILES+=	font.properties.tr		font.properties.zh_EUC_CN
SFILES+=	font.properties.zh_TW_Big5	font.properties.zh_TW_EUC_TW
SFILES+=	psfont.properties.ja		serialver.properties
SFILES+=	security/java.security
SUPPORT_FILES=	# empty
.for FILE in ${SFILES}
SUPPORT_FILES+=	${JAVA_HOME}/lib/${FILE}.default ${JAVA_HOME}/lib/${FILE}
.endfor

do-configure:
	cd ${WRKSRC}/lib; for file in ${SFILES}; do			\
		${MV} -f $$file $$file.default;				\
	done

.if ${OBJECT_FMT} == "ELF"
# This gross hack normalizes the shlib names so that automatic
# shared library handling will work.
post-patch:
	@(cd ${WRKSRC}/lib/i386/green_threads;				\
	${LN} -s libXm.so libXm.so.2;					\
	for X in lib*.so ;do						\
		if [ "$$X" = "libXm.so" ]; then continue; fi;		\
		if [ -f $$X.* ] ;then					\
			${MV} -f $$X $$X.* ;				\
			${LN} -s $$X.* $$X; 				\
		elif [ -f "$$X" ] ;then					\
			${MV} -f $$X $$X.${VERSION} ;			\
			${LN} -s $$X.${VERSION} $$X;			\
		fi ;							\
	done)
	${LN} -sf . ${WRKSRC}/jre
.endif

do-build: # empty, but cannot use NO_BUILD with java-env.mk

do-install:
	${RM} -f ${WRKSRC}/*.orig
	${INSTALL_PROGRAM_DIR} ${JAVA_HOME}
	cd ${WRKSRC} && ${PAX} -rw . ${JAVA_HOME}
	${RM} -f ${JAVA_HOME}/bin/i386/green_threads/javac.orig

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
