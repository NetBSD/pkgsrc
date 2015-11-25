# $NetBSD: Makefile,v 1.4 2015/11/25 12:49:46 jperkin Exp $

VERSION=	13.1.2
DISTNAME=	ideaIC-${VERSION:S/.0.0//}-src
PKGNAME=	intellij-idea-ce-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://download.jetbrains.com/idea/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.jetbrains.org/
COMMENT=	JetBrain's Java IDE
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/ideaIC-135.690
USE_LANGUAGES=	c c++
USE_JAVA=	yes
USE_JAVA2=	7

USE_TOOLS+=	pax tar

DEPENDS+=	snappy-java10-[0-9]*:../../devel/snappy-java10
BUILD_DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant

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

EXTDIR=			idea-IC-135.SNAPSHOT

do-build:
# Build Java part
	cd ${WRKSRC} \
		&& env ${MAKE_ENV} \
		${LOCALBASE}/bin/ant
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
	-I ${PKG_JAVA_HOME}/include/

do-install:
	cd ${WRKDIR} && \
	zcat ${WRKSRC}/out/artifacts/ideaIC-135.SNAPSHOT.tar.gz | tar xf -
	cd ${WRKDIR} && rm ${EXTDIR}/bin/fsnotifier*
	cd ${WRKDIR} && rm ${EXTDIR}/bin/libbreakgen.so
	cd ${WRKDIR} && rm ${EXTDIR}/bin/libbreakgen64.so
	cd ${WRKDIR} && rm -rf ${EXTDIR}/lib/libpty
	cd ${WRKDIR} && ${CP} ${WRKSRC}/native/fsNotifier/linux/fsnotifier \
		${EXTDIR}/bin
	cd ${WRKDIR} && ${CP} ${WRKSRC}/native/breakgen/libbreakgen.so \
		${EXTDIR}/bin
	cd ${WRKDIR}/${EXTDIR} && ${FIND} * -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/${PKGNAME}
	cd ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}/lib && \
	${RM} -f snappy-java-1.0.5.jar && \
	${LN} -sf ${PREFIX}/lib/java/snappy-java/snappy-java-1.0.5.jar .

.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
