# $NetBSD: Makefile,v 1.1 2013/11/24 10:44:34 ryoon Exp $

VERSION=	12.1.2
DISTNAME=	ideaIC-${VERSION}-src
PKGNAME=	intellij-idea-ce-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://download.jetbrains.com/idea/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.jetbrains.org/
COMMENT=	JetBrain's Java IDE
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/ideaIC-129.354
USE_LANGUAGES=	c c++
USE_JAVA=	yes
USE_JAVA2=	7

USE_TOOLS+=	pax tar

BUILD_DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant

FIND_PREFIX:=	ANTDIR=apache-ant
.include "../../mk/find-prefix.mk"

SUBST_CLASSES+=		dos_eol
SUBST_MESSAGE.dos_eol=	Removing DOS line-ends
SUBST_STAGE.dos_eol=	post-extract
SUBST_FILES.dos_eol=	native/fsNotifier/linux/*
SUBST_FILTER_CMD.dos_eol=	${TR} -d '\r'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.include "../../devel/libinotify/buildlink3.mk"
LIBINOTIFYFLAG=		-linotify
MNTENTCFILE=		mntent_compat.c
.endif

INSTALLATION_DIRS=	intellij-idea-ce-${VERSION}

EXTDIR=			idea-IC-129.SNAPSHOT

do-build:
# Build Java part
	cd ${WRKSRC} \
		&& env ${MAKE_ENV} \
		${ANTDIR}/bin/ant
# Build fsnotifier native binary
	cd ${WRKSRC}/native/fsNotifier/linux && \
		${CC} -Wall -std=c99 -D_BSD_SOURCE -D_XOPEN_SOURCE=500 \
		-D_NETBSD_SOURCE \
		-o fsnotifier \
		main.c inotify.c util.c \
		${MNTENTCFILE} \
		-I${BUILDLINK_PREFIX.libinotify}/include \
		${LIBINOTIFYFLAG} \
		-L${BUILDLINK_PREFIX.libinotify}/lib \
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libinotify}/lib
# Build libbreakgen native library
	cd ${WRKSRC}/native/breakgen && \
	${CC} -shared -fPIC -o libbreakgen.so AppMain.c \
	-I ${BUILDLINK_PREFIX.openjdk7}/java/openjdk7/include/

do-install:
	cd ${WRKDIR} && \
	zcat ${WRKSRC}/out/artifacts/ideaIC-129.SNAPSHOT.tar.gz | tar xf -
	cd ${WRKDIR} && rm ${EXTDIR}/bin/fsnotifier*
	cd ${WRKDIR} && rm ${EXTDIR}/bin/libbreakgen.so
	cd ${WRKDIR} && rm ${EXTDIR}/bin/libbreakgen64.so
	cd ${WRKDIR} && ${CP} ${WRKSRC}/native/fsNotifier/linux/fsnotifier \
		${EXTDIR}/bin
	cd ${WRKDIR} && ${CP} ${WRKSRC}/native/breakgen/libbreakgen.so \
		${EXTDIR}/bin
	cd ${WRKDIR}/${EXTDIR} && ${FIND} * -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/${PKGNAME}

.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
