# $NetBSD: Makefile,v 1.33 2003/05/06 17:41:39 jmmv Exp $
#

VERSION=	1.1.8
PKGNAME=	jdk-${VERSION}
PKGREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/java/i386/${VERSION}/ \
		ftp://ftp.de.netbsd.org/pub/NetBSD/misc/java/i386/${VERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jwise@netbsd.org
COMMENT=	Sun's Java(tm) Development Kit

LICENSE=	jdk-license

.include "../../mk/bsd.prefs.mk"

JVM_HOME=	${LOCALBASE}/java/jdk-${VERSION}

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

CHECK_SHLIBS=	no

USE_BUILDLINK2=	yes
USE_PKGINSTALL=	yes
NO_BUILD=	yes
NO_MTREE=	yes	# since we change PREFIX below

ONLY_FOR_PLATFORM= NetBSD-*-i386 Linux-*-i[3-6]86
RESTRICTED=	"No redistribution of the Java(tm) Development Kit"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

OWN_DIRS=	${PREFIX} ${PREFIX}/lib ${PREFIX}/lib/security
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
SUPPORT_FILES+=	${PREFIX}/lib/${FILE}.default ${PREFIX}/lib/${FILE}
.endfor

do-configure:
	cd ${WRKSRC}/lib; for file in ${SFILES}; do			\
		${MV} -f $$file $$file.default;				\
	done

.if ${OBJECT_FMT} == "ELF"
# This gross hack normalizes the shlib names so that automatic
# shared library handling will work.
pre-install:
	@(cd ${WRKSRC}/lib/i386/green_threads;				\
	${LN} -s libXm.so libXm.so.2;					\
	for X in lib*.so ;do						\
		if [ "$$X" = "libXm.so" ]; then continue; fi;		\
		if [ -f $$X.* ] ;then					\
			${MV} $$X $$X.* ;				\
			${LN} -s $$X.* $$X; 				\
		elif [ -f "$$X" ] ;then					\
			${MV} $$X $$X.${VERSION} ;			\
			${LN} -s $$X.${VERSION} $$X;			\
		fi ;							\
	done)
	${LN} -sf . ${WRKSRC}/jre
.endif

do-install:
	${RM} -f ${WRKSRC}/*.orig
	${INSTALL_PROGRAM_DIR} ${PREFIX}
	cd ${WRKSRC} && ${PAX} -rw . ${PREFIX}

.include "../../mk/bsd.pkg.mk"

# This needs to be after bsd.pkg.mk
PREFIX=		${JVM_HOME}
