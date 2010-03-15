# $NetBSD: Makefile,v 1.31 2010/03/15 14:25:07 joerg Exp $

DISTNAME=		speedtouch-1.3.1
PKGREVISION=		4
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=speedtouch/}
DISTFILES=		${DISTNAME}.tar.bz2

PKG_DESTDIR_SUPPORT=	user-destdir

#
# Firmware license and link from:
#	http://www.speedtouch.com/driver_upgrade_lx_3.0.1.2.htm
#
FIRMWARE_SRCS=		SpeedTouch330_firmware_3012.zip
SITES.${FIRMWARE_SRCS}=	http://www.speedtouch.com/download/drivers/USB/
DISTFILES+=		${FIRMWARE_SRCS}
EXTRACT_OPTS_ZIP=	-Laqo -d ${WRKDIR}/firmware

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.xsproject.org/speedtouch/
COMMENT=		Alcatel SpeedTouch USB ADSL modem driver
LICENSE=		speedtouch-firmware-license

DEPENDS+=		userppp>=001107:../../net/userppp

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
RCD_SCRIPTS=		adsl

PLIST_VARS+=		pppoa3

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "native"
PLIST.pppoa3=		yes
.else
CONFIGURE_ENV+=		ac_cv_lib_pthread_pthread_create=no
.endif

CHECK_PORTABILITY_SKIP+=	doc-linux/*

pre-extract:
	${MKDIR} ${WRKDIR}/firmware

SAMPLECONF=	${WRKSRC}/doc-bsd/ppp.conf.sample

INSTALLATION_DIRS=	libdata/speedtouch
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR} \
			installuser=${ROOT_USER}

post-build:
	${CP} ${SAMPLECONF} ${SAMPLECONF}.pre
	${SED} 's:/usr/local:${PREFIX}:' ${SAMPLECONF}.pre > ${SAMPLECONF}

post-install:
	${INSTALL_DATA} ${WRKDIR}/firmware/kqd6_3.012 ${DESTDIR}${PREFIX}/libdata/speedtouch
	${INSTALL_DATA} ${WRKDIR}/firmware/zzzl_3.012 ${DESTDIR}${PREFIX}/libdata/speedtouch

.include "../../mk/bsd.pkg.mk"
