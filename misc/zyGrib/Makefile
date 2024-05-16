# $NetBSD: Makefile,v 1.90 2024/05/16 06:15:12 wiz Exp $
#

DISTNAME=	zyGrib-8.0.1
PKGREVISION=	35
CATEGORIES=	misc
MASTER_SITES=	https://www.zygrib.org/getfile.php?file=
EXTRACT_SUFX=	.tgz

MAINTAINER=	plunky@NetBSD.org
HOMEPAGE=	https://www.zygrib.org/
COMMENT=	GRIB file viewer for weather data
LICENSE=	gnu-gpl-v3

DEPENDS+=	liberation-ttf-[0-9]*:../../fonts/liberation-ttf

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_LANGUAGES=	c c++
USE_TOOLS+=	make

CONFIGURE_ENV+=	QTDIR=${QTDIR}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing shared data paths.
SUBST_FILES.paths=	util/Util.h
SUBST_VARS.paths=	PREFIX

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/zyGrib/colors
INSTALLATION_DIRS+=	share/zyGrib/config
INSTALLATION_DIRS+=	share/zyGrib/gis
INSTALLATION_DIRS+=	share/zyGrib/img
INSTALLATION_DIRS+=	share/zyGrib/maps/gshhs
INSTALLATION_DIRS+=	share/zyGrib/stuff
INSTALLATION_DIRS+=	share/zyGrib/tr
INSTALL_FILES+=		colors/colors_binary.txt
INSTALL_FILES+=		colors/colors_cape_jkg.txt
INSTALL_FILES+=		colors/colors_cin_jkg.txt
INSTALL_FILES+=		colors/colors_clouds_black_pc.txt
INSTALL_FILES+=		colors/colors_clouds_white_pc.txt
INSTALL_FILES+=		colors/colors_current_kts.txt
INSTALL_FILES+=		colors/colors_deltatemp_celcius.txt
INSTALL_FILES+=		colors/colors_humidrel_pc.txt
INSTALL_FILES+=		colors/colors_rain_mmh.txt
INSTALL_FILES+=		colors/colors_snowdepth_m.txt
INSTALL_FILES+=		colors/colors_temp_celcius.txt
INSTALL_FILES+=		colors/colors_thetae_celcius.txt
INSTALL_FILES+=		colors/colors_thetae_celcius_1.txt
INSTALL_FILES+=		colors/colors_waveheight_m.txt
INSTALL_FILES+=		colors/colors_whitecap_prb.txt
INSTALL_FILES+=		colors/colors_whitecap_prb.txt.colors
INSTALL_FILES+=		colors/colors_wind_jet_kts.txt
INSTALL_FILES+=		colors/colors_wind_kts.txt
INSTALL_FILES+=		gis/cities_10k-more.txt.gz
INSTALL_FILES+=		gis/cities_3k-10k.txt.gz
INSTALL_FILES+=		gis/countries_en.txt.gz
INSTALL_FILES+=		gis/countries_fr.txt.gz
INSTALL_FILES+=		gis/states_en.txt.gz
INSTALL_FILES+=		gis/stations_metar.txt.gz
INSTALL_FILES+=		img/1leftarrow.png
INSTALL_FILES+=		img/1rightarrow.png
INSTALL_FILES+=		img/2leftarrow.png
INSTALL_FILES+=		img/2rightarrow.png
INSTALL_FILES+=		img/airport.png
INSTALL_FILES+=		img/anim.png
INSTALL_FILES+=		img/back.png
INSTALL_FILES+=		img/connect_no.png
INSTALL_FILES+=		img/down.png
INSTALL_FILES+=		img/drapeau_ar.png
INSTALL_FILES+=		img/drapeau_cz.png
INSTALL_FILES+=		img/drapeau_de.png
INSTALL_FILES+=		img/drapeau_en.png
INSTALL_FILES+=		img/drapeau_es.png
INSTALL_FILES+=		img/drapeau_fi.png
INSTALL_FILES+=		img/drapeau_fr.png
INSTALL_FILES+=		img/drapeau_gr.png
INSTALL_FILES+=		img/drapeau_it.png
INSTALL_FILES+=		img/drapeau_nl.png
INSTALL_FILES+=		img/drapeau_pt.png
INSTALL_FILES+=		img/drapeau_ru.png
INSTALL_FILES+=		img/exit.png
INSTALL_FILES+=		img/fileclose.png
INSTALL_FILES+=		img/fileopen.png
INSTALL_FILES+=		img/forward.png
INSTALL_FILES+=		img/help.png
INSTALL_FILES+=		img/info.png
INSTALL_FILES+=		img/media-floppy.png
INSTALL_FILES+=		img/meteoblue.png
INSTALL_FILES+=		img/network.png
INSTALL_FILES+=		img/player_eject.png
INSTALL_FILES+=		img/player_end.png
INSTALL_FILES+=		img/player_fwd.png
INSTALL_FILES+=		img/player_pause.png
INSTALL_FILES+=		img/player_play.png
INSTALL_FILES+=		img/player_playlist.png
INSTALL_FILES+=		img/player_rew.png
INSTALL_FILES+=		img/player_start.png
INSTALL_FILES+=		img/player_stop.png
INSTALL_FILES+=		img/printer.png
INSTALL_FILES+=		img/reload.png
INSTALL_FILES+=		img/resource.rc
INSTALL_FILES+=		img/spreadsheet.png
INSTALL_FILES+=		img/time_icon.png
INSTALL_FILES+=		img/up.png
INSTALL_FILES+=		img/viewmag+.png
INSTALL_FILES+=		img/viewmag-.png
INSTALL_FILES+=		img/viewmag1.png
INSTALL_FILES+=		img/viewmagfit.png
INSTALL_FILES+=		img/zyGrib.icns
INSTALL_FILES+=		img/zyGrib_32.ico
INSTALL_FILES+=		img/zyGrib_32.xpm
INSTALL_FILES+=		maps/gshhs/README.gshhs
INSTALL_FILES+=		maps/gshhs/README.gshhs.rangs
INSTALL_FILES+=		maps/gshhs/gshhs_2.rim
INSTALL_FILES+=		maps/gshhs/gshhs_3.rim
INSTALL_FILES+=		maps/gshhs/gshhs_4.rim
INSTALL_FILES+=		maps/gshhs/rangs_2.cat
INSTALL_FILES+=		maps/gshhs/rangs_2.cel
INSTALL_FILES+=		maps/gshhs/rangs_3.cat
INSTALL_FILES+=		maps/gshhs/rangs_3.cel
INSTALL_FILES+=		maps/gshhs/rangs_4.cat
INSTALL_FILES+=		maps/gshhs/rangs_4.cel
INSTALL_FILES+=		maps/gshhs/wdb_borders_c.b
INSTALL_FILES+=		maps/gshhs/wdb_borders_i.b
INSTALL_FILES+=		maps/gshhs/wdb_borders_l.b
INSTALL_FILES+=		maps/gshhs/wdb_rivers_c.b
INSTALL_FILES+=		maps/gshhs/wdb_rivers_i.b
INSTALL_FILES+=		maps/gshhs/wdb_rivers_l.b
INSTALL_FILES+=		stuff/boat_parameters.csv
INSTALL_FILES+=		tr/zyGrib_ar.qm
INSTALL_FILES+=		tr/zyGrib_ar.ts
INSTALL_FILES+=		tr/zyGrib_cz.qm
INSTALL_FILES+=		tr/zyGrib_cz.ts
INSTALL_FILES+=		tr/zyGrib_de.qm
INSTALL_FILES+=		tr/zyGrib_de.ts
INSTALL_FILES+=		tr/zyGrib_es.qm
INSTALL_FILES+=		tr/zyGrib_es.ts
INSTALL_FILES+=		tr/zyGrib_fi.qm
INSTALL_FILES+=		tr/zyGrib_fi.ts
INSTALL_FILES+=		tr/zyGrib_fr.qm
INSTALL_FILES+=		tr/zyGrib_fr.ts
INSTALL_FILES+=		tr/zyGrib_gr.qm
INSTALL_FILES+=		tr/zyGrib_gr.ts
INSTALL_FILES+=		tr/zyGrib_it.qm
INSTALL_FILES+=		tr/zyGrib_it.ts
INSTALL_FILES+=		tr/zyGrib_nl.qm
INSTALL_FILES+=		tr/zyGrib_nl.ts
INSTALL_FILES+=		tr/zyGrib_pt.qm
INSTALL_FILES+=		tr/zyGrib_pt.ts
INSTALL_FILES+=		tr/zyGrib_ru.qm
INSTALL_FILES+=		tr/zyGrib_ru.ts

.include "../../mk/bsd.prefs.mk"

CXXFLAGS+=	-DACCEPT_USE_OF_DEPRECATED_PROJ_API_H

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake "QMAKE_RPATHDIR+=${QWT_DIR}/lib" "QMAKE_LIBDIR+=${QWT_DIR}/lib"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zyGrib ${DESTDIR}${PREFIX}/bin
.for f in ${INSTALL_FILES}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/data/${f} ${DESTDIR}${PREFIX}/share/zyGrib/${f}
.endfor

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../geography/libnova/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qwt6-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
