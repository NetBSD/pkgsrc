# $NetBSD: Makefile,v 1.1.1.1 2008/11/04 11:11:50 markd Exp $

DISTNAME=	strigi-0.5.10
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=strigi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://strigi.sourceforge.net/
COMMENT=	Small fast desktop searching program

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config perl
USE_CMAKE=	yes

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/pset.h)
RT_LIB_SCHED=	-lrt
.else
RT_LIB_SCHED=	# empty
.endif

.if !empty(RT_LIB_SCHED)
# these use sched_setscheduler
CMAKE_ARGS+=	-Dstrigidaemon_LIBS=${RT_LIB_SCHED}
CMAKE_ARGS+=	-Dtest_LIBS=${RT_LIB_SCHED}
.endif

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libclucene/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
