# $NetBSD: Makefile,v 1.30 2002/10/13 07:48:52 jlam Exp $
#

VERSION=	1.1.8
PKGNAME=	jdk-${VERSION}
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/java/i386/${VERSION}/ \
		ftp://ftp.de.netbsd.org/pub/NetBSD/misc/java/i386/${VERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.quick.com.au/java/
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

USE_BUILDLINK2=	# defined
NO_BUILD=	# defined
NO_MTREE=	# defined, since we change PREFIX below

ONLY_FOR_PLATFORM= NetBSD-*-i386 Linux-*-i[3-6]86
RESTRICTED=	"No redistribution of the Java(tm) Development Kit"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

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
.endif

do-install:
	${RM} -f ${WRKSRC}/*.orig
	${INSTALL_PROGRAM_DIR} ${PREFIX}
	cd ${WRKSRC} && ${PAX} -rw . ${PREFIX}

.include "../../mk/bsd.pkg.mk"

# This needs to be after bsd.pkg.mk 
PREFIX=		${JVM_HOME}
