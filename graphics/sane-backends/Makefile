# $NetBSD: Makefile,v 1.23 2005/09/27 09:29:56 wiz Exp $

.include "Makefile.common"
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc.

DISTNAME=       sane-backends-${SANE_VERSION}

BUILD_USES_MSGFMT=	YES
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--with-gphoto2=no
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/sane-${SANE_VERSION}

.if (${OPSYS} == "SunOS")
PLIST_SUBST+=	SANE_PINT="@comment "
PLIST_SUBST+=	SANE_SM3600="@comment "
.elif (${OPSYS} == "Linux")
PLIST_SUBST+=	SANE_PINT="@comment "
PLIST_SUBST+=   SANE_SM3600=""
.else
PLIST_SUBST+=	SANE_PINT=""
PLIST_SUBST+=	SANE_SM3600=""
.endif

USE_PKGINSTALL=	YES
OWN_DIRS+=	${PKG_SYSCONFDIR}/sane.d
EGDIR=		${PREFIX}/share/examples/sane
.for f in abaton.conf agfafocus.conf apple.conf artec.conf \
artec_eplus48u.conf avision.conf bh.conf canon.conf canon630u.conf \
coolscan.conf coolscan2.conf dc210.conf dc240.conf dc25.conf dll.conf \
dmc.conf epson.conf fujitsu.conf genesys.conf gt68xx.conf hp.conf \
hp5400.conf ibm.conf leo.conf ma1509.conf matsushita.conf \
microtek.conf microtek2.conf mustek.conf mustek_usb.conf nec.conf \
net.conf pie.conf plustek.conf plustek_pp.conf ricoh.conf s9036.conf \
saned.conf sceptre.conf sharp.conf sm3840.conf snapscan.conf \
sp15c.conf st400.conf tamarack.conf teco1.conf teco2.conf teco3.conf \
test.conf u12.conf umax.conf umax1220u.conf umax_pp.conf
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/sane.d/${f}
.endfor

.if (${OPSYS} == "Linux")
.for f in qcam.conf v4l.conf
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/sane.d/${f}
.endfor
.endif

.if (${OPSYS} != "SunOS")
. include "../../devel/libusb/buildlink3.mk"
.endif
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
