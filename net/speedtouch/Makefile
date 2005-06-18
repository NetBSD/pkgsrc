# $NetBSD: Makefile,v 1.17 2005/06/18 11:29:10 kristerw Exp $

DISTNAME=		speedtouch-1.3.1
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=speedtouch/}
DISTFILES=		${DISTNAME}.tar.bz2

#
# Firmware license and link from:
#	http://www.speedtouch.com/driver_upgrade_lx_3.0.1.2.htm
#
FIRMWARE_SRCS=		SpeedTouch330_firmware_3012.zip
SITES_${FIRMWARE_SRCS}=	http://www.speedtouch.com/download/drivers/USB/
DISTFILES+=		${FIRMWARE_SRCS}
EXTRACT_CMD_OPTS.zip=	-Laqo -d ${WRKDIR}/firmware

LICENSE=		speedtouch-firmware-license

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://www.xsproject.org/speedtouch/
COMMENT=		Alcatel SpeedTouch USB ADSL modem driver

DEPENDS+=		userppp>=001107:../../net/userppp

USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
RCD_SCRIPTS=		adsl

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "native"
PLIST_SUBST+=           PPPOA3=""
.else
PLIST_SUBST+=           PPPOA3="@comment "
CONFIGURE_ENV+=		ac_cv_lib_pthread_pthread_create=no
.endif

pre-extract:
	${MKDIR} ${WRKDIR}/firmware

SAMPLECONF=	${WRKSRC}/doc-bsd/ppp.conf.sample

post-build:
	${CP} ${SAMPLECONF} ${SAMPLECONF}.pre
	${SED} 's:/usr/local:${PREFIX}:' ${SAMPLECONF}.pre > ${SAMPLECONF}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/speedtouch
	${INSTALL_DATA} ${WRKDIR}/firmware/kqd6_3.012 ${PREFIX}/libdata/speedtouch
	${INSTALL_DATA} ${WRKDIR}/firmware/zzzl_3.012 ${PREFIX}/libdata/speedtouch

.include "../../mk/bsd.pkg.mk"
