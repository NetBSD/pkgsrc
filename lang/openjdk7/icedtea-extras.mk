# $NetBSD: icedtea-extras.mk,v 1.16 2015/02/23 13:34:56 tnn Exp $

RHINO=				rhino1_7R5
RHINO_TGZ=			${RHINO}.zip
SITES.${RHINO_TGZ}=		https://github.com/mozilla/rhino/releases/download/Rhino1_7R5_RELEASE/
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
