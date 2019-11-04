# $NetBSD: data.mk,v 1.1 2019/11/04 18:35:21 nros Exp $
#
XYGRIBDV=	1.1.1
XYGRIBDS=	https://github.com/openGribs/XyGrib/releases/download/v${XYGRIBDV}/

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	XyGrib___High_Resolution_Maps.tar.gz
DISTFILES+=	XyGrib___cities_files.tar.gz

SITES.XyGrib___High_Resolution_Maps.tar.gz=	${XYGRIBDS}
SITES.XyGrib___cities_files.tar.gz=		${XYGRIBDS}

DIST_SUBDIR=	XyGrib-${XYGRIBDV}

INSTALL_CITIES_FILES=	cities_0-300.txt.gz
INSTALL_CITIES_FILES+=	cities_300-1k.txt.gz
INSTALL_CITIES_FILES+=	cities_1k-3k.txt.gz

.PHONY: install-cities
install-cities:
.for f in ${INSTALL_CITIES_FILES}
	${INSTALL_DATA} ${WRKDIR}/${f} \
		${DESTDIR}${PREFIX}/share/openGribs/XyGrib/data/gis/${f}
.endfor
post-install: install-cities
