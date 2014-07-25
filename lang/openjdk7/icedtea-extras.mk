# $NetBSD: icedtea-extras.mk,v 1.13 2014/07/25 23:24:13 ryoon Exp $

# Needed to extract icedtea
EXTRACT_USING=			bsdtar

DIST_SUBDIR=			openjdk7

ICEDTEA=			icedtea-2.5.1
ICEDTEA_TGZ=			${ICEDTEA}.tar.xz
SITES.${ICEDTEA_TGZ}=		http://icedtea.wildebeest.org/download/source/
DISTFILES+=			${ICEDTEA_TGZ}
EXTRACT_ONLY+=			${ICEDTEA_TGZ}

# Keep icedtea-web distfile in sync with www/icedtea-web/Makefile
ICEDTEA_WEB=			icedtea-web-81dfc0552a1c
ICEDTEA_WEB_TGZ=		icedtea-web-81dfc0552a1c.tar.bz2
SITES.${ICEDTEA_WEB_TGZ}=	-http://icedtea.classpath.org/hg/icedtea-web/archive/81dfc0552a1c.tar.bz2
DISTFILES+=			${ICEDTEA_WEB_TGZ}
EXTRACT_ONLY+=			${ICEDTEA_WEB_TGZ}

RHINO=				rhino1_7R4
RHINO_TGZ=			${RHINO}.zip
SITES.${RHINO_TGZ}=		https://github.com/downloads/mozilla/rhino/
DISTFILES+=			${RHINO_TGZ}
EXTRACT_ONLY+=			${RHINO_TGZ}

# fixme: Should depend on devel/apache-ant?
ANT=				apache-ant-1.9.4
ANT_TGZ=			${ANT}-bin.tar.bz2
SITES.${ANT_TGZ}=		http://archive.apache.org/dist/ant/binaries/
DISTFILES+=			${ANT_TGZ}
EXTRACT_ONLY+=			${ANT_TGZ}
ANT_BIN=			${WRKDIR}/${ANT}/bin
PREPEND_PATH+=			${ANT_BIN}
