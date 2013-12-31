# $NetBSD: icedtea-extras.mk,v 1.12 2013/12/31 17:11:36 abs Exp $

# Needed to extract icedtea
EXTRACT_USING=			bsdtar

DIST_SUBDIR=			openjdk7

ICEDTEA=			icedtea7-02bbff3d71ff
ICEDTEA_TGZ=			icedtea7-02bbff3d71ff.tar.bz2
SITES.${ICEDTEA_TGZ}=		-http://icedtea.classpath.org/hg/icedtea7/archive/02bbff3d71ff.tar.bz2
DISTFILES+=			${ICEDTEA_TGZ}
EXTRACT_ONLY+=			${ICEDTEA_TGZ}

# Keep icedtea-web distfile in sync with www/icedtea-web/Makefile
ICEDTEA_WEB=			icedtea-web-81dfc0552a1c
ICEDTEA_WEB_TGZ=		icedtea-web-81dfc0552a1c.tar.bz2
SITES.${ICEDTEA_WEB_TGZ}=	-http://icedtea.classpath.org/hg/icedtea-web/archive/81dfc0552a1c.tar.bz2
DISTFILES+=			${ICEDTEA_WEB_TGZ}
EXTRACT_ONLY+=			${ICEDTEA_WEB_TGZ}

RHINO=				rhino1_7R3
RHINO_TGZ=			${RHINO}.zip
SITES.${RHINO_TGZ}=		${MASTER_SITE_MOZILLA:=js/}
DISTFILES+=			${RHINO_TGZ}
EXTRACT_ONLY+=			${RHINO_TGZ}

# fixme: Should depend on devel/apache-ant?
ANT=				apache-ant-1.8.4
ANT_TGZ=			${ANT}-bin.tar.bz2
SITES.${ANT_TGZ}=		http://archive.apache.org/dist/ant/binaries/
DISTFILES+=			${ANT_TGZ}
EXTRACT_ONLY+=			${ANT_TGZ}
ANT_BIN=			${WRKDIR}/${ANT}/bin
PREPEND_PATH+=			${ANT_BIN}

JAXP_TGZ=			jaxp145_01.zip
SITES.${JAXP_TGZ}=		http://icedtea.classpath.org/download/drops/
DISTFILES+=			${JAXP_TGZ}

JAXWS_TGZ=			jdk7-jaxws2_2_4-b03-2011_05_27.zip
SITES.${JAXWS_TGZ}=		http://icedtea.classpath.org/download/drops/
DISTFILES+=			${JAXWS_TGZ}

JAF_TGZ=			jdk7-jaf-2010_08_19.zip
SITES.${JAF_TGZ}=		http://icedtea.classpath.org/download/drops/
DISTFILES+=			${JAF_TGZ}
