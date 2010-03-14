# $NetBSD: Makefile,v 1.7 2010/03/14 16:32:16 wiz Exp $
#

DISTNAME=	zyGrib-3.5.1
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.zygrib.org/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	plunky@rya-online.net
HOMEPAGE=	http://www.zygrib.org/
COMMENT=	GRIB file viewer for weather data
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/zyGrib/src
USE_LANGUAGES=	c c++
USE_TOOLS+=	make

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_MESSAGE.paths=	Fixing shared data paths.
SUBST_FILES.paths=	GisReader.cpp GribAnimator.cpp
SUBST_FILES.paths+=	MenuBar.cpp MainWindow.cpp main.cpp
SUBST_SED.paths+=	-e "s|maps/|${PREFIX}/share/zyGrib/maps/|"
SUBST_SED.paths+=	-e "s|img/|${PREFIX}/share/zyGrib/img/|"
SUBST_SED.paths+=	-e "s|tr/|${PREFIX}/share/zyGrib/tr/|"

INSTALLATION_DIRS+=	bin share/zyGrib/img
INSTALLATION_DIRS+=	share/zyGrib/maps/gis
INSTALLATION_DIRS+=	share/zyGrib/maps/gshhs
INSTALLATION_DIRS+=	share/zyGrib/tr

INSTALL_FILES=	img/1leftarrow.png
INSTALL_FILES+=	img/1rightarrow.png
INSTALL_FILES+=	img/2leftarrow.png
INSTALL_FILES+=	img/2rightarrow.png
INSTALL_FILES+=	img/anim.png
INSTALL_FILES+=	img/back.png
INSTALL_FILES+=	img/connect_no.png
INSTALL_FILES+=	img/down.png
INSTALL_FILES+=	img/exit.png
INSTALL_FILES+=	img/fileclose.png
INSTALL_FILES+=	img/fileopen.png
INSTALL_FILES+=	img/forward.png
INSTALL_FILES+=	img/help.png
INSTALL_FILES+=	img/info.png
INSTALL_FILES+=	img/network.png
INSTALL_FILES+=	img/player_eject.png
INSTALL_FILES+=	img/player_end.png
INSTALL_FILES+=	img/player_fwd.png
INSTALL_FILES+=	img/player_pause.png
INSTALL_FILES+=	img/player_play.png
INSTALL_FILES+=	img/player_playlist.png
INSTALL_FILES+=	img/player_rew.png
INSTALL_FILES+=	img/player_start.png
INSTALL_FILES+=	img/player_stop.png
INSTALL_FILES+=	img/reload.png
INSTALL_FILES+=	img/up.png
INSTALL_FILES+=	img/viewmag+.png
INSTALL_FILES+=	img/viewmag-.png
INSTALL_FILES+=	img/viewmag1.png
INSTALL_FILES+=	img/viewmagfit.png
INSTALL_FILES+=	maps/gis/cities.txt.gz
INSTALL_FILES+=	maps/gis/countries_en.txt.gz
INSTALL_FILES+=	maps/gis/countries_fr.txt.gz
INSTALL_FILES+=	maps/gshhs/README.gshhs
INSTALL_FILES+=	maps/gshhs/README.gshhs.rangs
INSTALL_FILES+=	maps/gshhs/gshhs_2.rim
INSTALL_FILES+=	maps/gshhs/gshhs_3.rim
INSTALL_FILES+=	maps/gshhs/gshhs_4.rim
INSTALL_FILES+=	maps/gshhs/rangs_2.cat
INSTALL_FILES+=	maps/gshhs/rangs_2.cel
INSTALL_FILES+=	maps/gshhs/rangs_3.cat
INSTALL_FILES+=	maps/gshhs/rangs_3.cel
INSTALL_FILES+=	maps/gshhs/rangs_4.cat
INSTALL_FILES+=	maps/gshhs/rangs_4.cel
INSTALL_FILES+=	maps/gshhs/wdb_borders_c.b
INSTALL_FILES+=	maps/gshhs/wdb_borders_i.b
INSTALL_FILES+=	maps/gshhs/wdb_borders_l.b
INSTALL_FILES+=	maps/gshhs/wdb_rivers_c.b
INSTALL_FILES+=	maps/gshhs/wdb_rivers_i.b
INSTALL_FILES+=	maps/gshhs/wdb_rivers_l.b
INSTALL_FILES+=	tr/zyGrib_de.qm
INSTALL_FILES+=	tr/zyGrib_de.ts
INSTALL_FILES+=	tr/zyGrib_en.qm
INSTALL_FILES+=	tr/zyGrib_en.ts
INSTALL_FILES+=	tr/zyGrib_es.qm
INSTALL_FILES+=	tr/zyGrib_es.ts
INSTALL_FILES+=	tr/zyGrib_it.qm
INSTALL_FILES+=	tr/zyGrib_it.ts
INSTALL_FILES+=	tr/zyGrib_nl.qm
INSTALL_FILES+=	tr/zyGrib_nl.ts
INSTALL_FILES+=	tr/zyGrib_ru.qm
INSTALL_FILES+=	tr/zyGrib_ru.ts

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../zyGrib ${DESTDIR}${PREFIX}/bin
.for f in ${INSTALL_FILES}
	${INSTALL_DATA} ${WRKDIR}/zyGrib/${f} ${DESTDIR}${PREFIX}/share/zyGrib/${f}
.endfor

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
