# $NetBSD: Makefile,v 1.2 2021/02/21 13:29:00 wiz Exp $

DISTNAME=	imx_usb_loader-0.0.0.20210220
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=boundarydevices/}
GITHUB_PROJECT=	imx_usb_loader
GITHUB_TAG=	30b43d69770cd69e84c045dc9dcabb1f3e9d975a

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boundarydevices/imx_usb_loader
COMMENT=	SDP bootloader for Freescale i.MX5/i.MX6/i.MX7 and Vybrid SoC
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config gmake
MAKE_FLAGS+=	prefix=${PREFIX}

INSTALLATION_DIRS+=	share/examples/imx_usb_loader

EGDIR=		share/examples/imx_usb_loader
REQD_DIRS=	${PKG_SYSCONFDIR}/imx-loader.d
LOADERCFGS=	imx_usb.conf mx50_usb_work.conf
LOADERCFGS+=	mx51_usb_work.conf mx53_usb_work.conf
LOADERCFGS+=	mx6_usb_sdp_spl.conf mx6_usb_work.conf
LOADERCFGS+=	mx6ull_usb_work.conf mx7_usb_work.conf
LOADERCFGS+=	mx7ulp_usb_work.conf mx8m_usb_sdp_spl.conf
LOADERCFGS+=	mx8mm_usb_work.conf mx8mn_usb_work.conf
LOADERCFGS+=	mx8mq_usb_work.conf vybrid_usb_work.conf

.for i in ${LOADERCFGS}
CONF_FILES+=	${EGDIR}/imx-loader.d/${i} ${PKG_SYSCONFDIR}/imx-loader.d/${i}
.endfor

post-install:
	mv ${DESTDIR}${PREFIX}/etc/imx-loader.d ${DESTDIR}${PREFIX}/share/examples/imx_usb_loader

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
