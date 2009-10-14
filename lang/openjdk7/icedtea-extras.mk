# $NetBSD: icedtea-extras.mk,v 1.1.1.1 2009/10/14 11:26:15 tnn Exp $

# Needed to extract icedtea
EXTRACT_USING=			gtar

DIST_SUBDIR=			openjdk7

ICEDTEA=			icedtea-175529fae103
ICEDTEA_TGZ=			175529fae103.tar.bz2
SITES.${ICEDTEA_TGZ}=		http://icedtea.classpath.org/hg/icedtea/archive/
DISTFILES+=			${ICEDTEA_TGZ}
EXTRACT_ONLY+=			${ICEDTEA_TGZ}

XALAN=				xalan-j_2_7_1
XALAN_TGZ=			${XALAN}-bin.zip
SITES.${XALAN_TGZ}=		${MASTER_SITE_APACHE:=xml/xalan-j/}
DISTFILES+=			${XALAN_TGZ}
EXTRACT_ONLY+=			${XALAN_TGZ}

RHINO=				rhino1_7R2
RHINO_TGZ=			${RHINO}.zip
SITES.${RHINO_TGZ}=		${MASTER_SITE_MOZILLA:=js/}
DISTFILES+=			${RHINO_TGZ}
EXTRACT_ONLY+=			${RHINO_TGZ}

# fixme: Should depend on devel/apache-ant?
ANT=				apache-ant-1.7.1
ANT_TGZ=			${ANT}-bin.zip
SITES.${ANT_TGZ}=		${MASTER_SITE_APACHE:=ant/binaries/}
DISTFILES+=			${ANT_TGZ}
EXTRACT_ONLY+=			${ANT_TGZ}
ANT_BIN=			${WRKDIR}/${ANT}/bin
PREPEND_PATH+=			${ANT_BIN}

ICEDTEA_CONFIGURE_ARGS=	\
	  --with-xalan2-jar=${WRKDIR}/${XALAN}/xalan.jar \
	  --with-xalan2-serializer-jar=${WRKDIR}/${XALAN}/serializer.jar \
	  --with-xerces2-jar=${WRKDIR}/${XALAN}/xercesImpl.jar \
	  --with-rhino=${WRKDIR}/${RHINO}/js.jar

.if defined(ICEDTEA_PACKAGE)
CONFIGURE_ARGS+=	${ICEDTEA_CONFIGURE_ARGS}
CONFIGURE_ARGS+=	--with-jdk-home=${PREFIX}/java/openjdk7

USE_LANGUAGES=		c c++
USE_TOOLS+=	gawk pkg-config autoconf automake
CONFIGURE_ENV+=	ac_cv_path_MD5SUM=/usr/bin/true

pre-configure: icedtea-autoconf
.PHONY: icedtea-autoconf
icedtea-autoconf:
	cd ${WRKDIR}/${ICEDTEA} && ${SETENV} ${CONFIGURE_ENV} autoreconf -if

post-extract: icedtea-post-extract
.PHONY: icedtea-post-extract
icedtea-post-extract:
	chmod +x ${ANT_BIN}/ant

BUILDLINK_DEPMETHOD.cups?=     build
.include "../../print/cups/buildlink3.mk"
.include "../../lang/openjdk7/buildlink3.mk"
.include "../../devel/xulrunner/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXp?=	build
.include "../../x11/libXp/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXtst?=	build
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif
