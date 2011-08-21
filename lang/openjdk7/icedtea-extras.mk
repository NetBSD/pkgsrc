# $NetBSD: icedtea-extras.mk,v 1.10 2011/08/21 22:57:54 tnn Exp $

# Needed to extract icedtea
EXTRACT_USING=			bsdtar

DIST_SUBDIR=			openjdk7

ICEDTEA=			icedtea7-8ac25d11a9e5
ICEDTEA_TGZ=			8ac25d11a9e5.tar.bz2
SITES.${ICEDTEA_TGZ}=		http://icedtea.classpath.org/hg/icedtea7/archive/
DISTFILES+=			${ICEDTEA_TGZ}
EXTRACT_ONLY+=			${ICEDTEA_TGZ}

ICEDTEA_WEB=			icedtea-web-61e08e67b176
ICEDTEA_WEB_TGZ=		61e08e67b176.tar.bz2
SITES.${ICEDTEA_WEB_TGZ}=	http://icedtea.classpath.org/hg/icedtea-web/archive/
DISTFILES+=			${ICEDTEA_WEB_TGZ}
EXTRACT_ONLY+=			${ICEDTEA_WEB_TGZ}

RHINO=				rhino1_7R3
RHINO_TGZ=			${RHINO}.zip
SITES.${RHINO_TGZ}=		${MASTER_SITE_MOZILLA:=js/}
DISTFILES+=			${RHINO_TGZ}
EXTRACT_ONLY+=			${RHINO_TGZ}

# fixme: Should depend on devel/apache-ant?
ANT=				apache-ant-1.8.1
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
