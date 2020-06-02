# $NetBSD: Makefile,v 1.77 2020/06/02 08:22:57 adam Exp $

DISTNAME=	strigi-0.7.8
PKGREVISION=	35
CATEGORIES=	sysutils
MASTER_SITES=	http://www.vandenoever.info/software/strigi/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://strigi.sourceforge.net/
COMMENT=	Small fast desktop searching program
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++11
USE_TOOLS+=	gmake pkg-config perl
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	src/streamanalyzer/libstreamanalyzer.pc.cmake
PKGCONFIG_OVERRIDE+=	src/streams/libstreams.pc.cmake

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/pset.h)
RT_LIB_SCHED=	-lrt
.else
RT_LIB_SCHED=	# empty
.endif

LDFLAGS.Darwin+=	-lclucene-shared
LDFLAGS.DragonFly+=	-lclucene-shared
LDFLAGS.FreeBSD+=	-lclucene-shared
LDFLAGS.NetBSD+=	-lclucene-shared
LDFLAGS.Linux+=		-lclucene-shared

CFLAGS.SunOS+=	-DCMAKE_HAVE_PTHREAD_CREATE
LDFLAGS.SunOS+=	-mimpure-text -lrt -lsocket -lclucene-shared

CMAKE_ARGS+=	-DENABLE_EXIV2=OFF
CMAKE_ARGS+=	-DENABLE_FFMPEG=OFF
.if !empty(RT_LIB_SCHED)
# these use sched_setscheduler
CMAKE_ARGS+=	-Dstrigidaemon_LIBS=${RT_LIB_SCHED}
CMAKE_ARGS+=	-Dtest_LIBS=${RT_LIB_SCHED}
.endif

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

BUILDLINK_API_DEPENDS.libclucene+=	libclucene>=2.3.3.4
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libclucene/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
