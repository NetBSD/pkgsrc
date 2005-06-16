# $NetBSD: Makefile,v 1.9 2005/06/16 06:57:39 jlam Exp $

DISTNAME=	madman-0.93
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=madman/}

MAINTAINER=	ove@elektro-eel.org
HOMEPAGE=	http://madman.sourceforge.net/
COMMENT=	Powerful audio manager for large collections

BUILD_DEPENDS+=		scons>=0.96:../../devel/scons

GCC_REQD=		3.0

INSTALLATION_DIRS=	bin

post-extract:
	${MV} ${WRKSRC}/httpd/make_webdata ${WRKSRC}/httpd/make_webdata.org
	${SED} -e 's,#! /usr/bin/env python,#!${PYTHONBIN},' ${WRKSRC}/httpd/make_webdata.org > ${WRKSRC}/httpd/make_webdata
	${CHMOD} 755 ${WRKSRC}/httpd/make_webdata
	${MV} ${WRKSRC}/main/SConscript ${WRKSRC}/main/SConscript.org
	${AWK} '{print} NR == 20 {print "myenv.Append(LINKFLAGS = \"-Wl,-R${X11BASE}/lib,-R${LOCALBASE}/lib,-R${LOCALBASE}${QTDIR}/lib\")"}' ${WRKSRC}/main/SConscript.org > ${WRKSRC}/main/SConscript

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons -C ${WRKSRC} prefix=${PREFIX} \
	qt_directory=${QTDIR} add_c_include_dirs=${LOCALBASE}/include add_c_lib_dirs=${WRKDIR}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/madman ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib/madman
	${INSTALL_DATA_DIR} ${PREFIX}/lib/madman/plugins
	for plugin in burn_to_audio_cd burn_to_data_cd export_m3u move_to_trash; do \
		${INSTALL_DATA} -m0755 ${WRKSRC}/plugins/$$plugin ${PREFIX}/lib/madman/plugins; \
	done

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
