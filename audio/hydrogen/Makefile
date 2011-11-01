# $NetBSD: Makefile,v 1.22 2011/11/01 06:00:38 sbd Exp $

DISTNAME=	hydrogen-0.9.4.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hydrogen/}

MAINTAINER=	chris.wareham@btinternet.com
HOMEPAGE=	http://www.hydrogen-music.org/
COMMENT=	Real time drum machine/sequencer

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

BUILD_DEPENDS+=		scons>=0.98:../../devel/scons
BUILD_DEPENDS+=		subversion-base>=1.0:../../devel/subversion-base

MAKE_ENV+=	QTDIR=${PREFIX}/qt4 PATH=$$PATH:${PREFIX}/qt4/bin
SCONS_ARGS=	libarchive=1 jack=0 lrdf=0 alsa=0 QTDIR=${QTDIR}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons DESTDIR=${DESTDIR} prefix=${PREFIX} ${SCONS_ARGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons DESTDIR=${DESTDIR} prefix=${PREFIX} ${SCONS_ARGS} install

.include "../../mk/bsd.prefs.mk"

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
