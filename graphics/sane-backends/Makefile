# $NetBSD: Makefile,v 1.73 2020/06/13 20:54:32 leot Exp $

.include "Makefile.common"
MASTER_SITES=	https://gitlab.com/sane-project/backends/uploads/c3dd60c9e054b5dee1e7b01a7edc98b0/
COMMENT=	API for access to scanners, digital cameras, frame grabbers, etc

DISTNAME=	sane-backends-${SANE_VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

USE_TOOLS+=		msgfmt msgmerge pkg-config
USE_PKGLOCALEDIR=	YES

# c++11 is needed for genesys backend
USE_LANGUAGES=		c c++11

# C++11
GCC_REQD+=		4.8

CONFIGURE_ARGS+=	--with-gphoto2=no
CONFIGURE_ARGS+=	--without-snmp
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

CONFIGURE_ENV.SunOS+=	ac_cv_func_inet_ntop=yes
CONFIGURE_ENV.SunOS+=	ac_cv_func_inet_pton=yes

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		mustek pint sm3600 kvs40xx

.if (${OPSYS} == "SunOS") || (${OPSYS} == "Linux") || (${OPSYS} == "DragonFly") || (${OPSYS} == "FreeBSD")
PLIST.sm3600=		yes
.elif (${OPSYS} == "Darwin")
PLIST.mustek=		yes
PLIST.sm3600=		yes
PLIST.kvs40xx=		yes
.else
PLIST.pint=		yes
PLIST.sm3600=		yes
.endif

OWN_DIRS+=	${PKG_SYSCONFDIR}/sane.d
EGDIR=		${PREFIX}/share/examples/sane
.for f in abaton.conf agfafocus.conf apple.conf artec.conf \
artec_eplus48u.conf avision.conf bh.conf canon.conf canon630u.conf \
canon_dr.conf cardscan.conf coolscan.conf coolscan2.conf coolscan3.conf \
dc210.conf dc240.conf dc25.conf dell1600n_net.conf dll.conf dmc.conf \
epjitsu.conf epson.conf epson2.conf epsonds.conf fujitsu.conf \
genesys.conf gt68xx.conf hp.conf hp3900.conf \
hp4200.conf hp5400.conf hs2p.conf ibm.conf kodak.conf \
kvs1025.conf leo.conf lexmark.conf \
ma1509.conf matsushita.conf \
microtek.conf microtek2.conf mustek.conf mustek_usb.conf \
nec.conf net.conf \
p5.conf pie.conf pieusb.conf pixma.conf plustek.conf plustek_pp.conf \
ricoh.conf rts8891.conf \
s9036.conf saned.conf sceptre.conf sharp.conf sm3840.conf snapscan.conf \
sp15c.conf st400.conf stv680.conf \
tamarack.conf teco1.conf teco2.conf teco3.conf \
test.conf u12.conf umax.conf umax1220u.conf umax_pp.conf xerox_mfp.conf
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/sane.d/${f}
.endfor

.if (${OPSYS} == "Linux")
.  for f in qcam.conf v4l.conf
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/sane.d/${f}
.  endfor
.endif

.include "options.mk"
.include "../../devel/libusb1/buildlink3.mk"
.if (${OPSYS} == "Linux")
.include "../../graphics/libv4l/buildlink3.mk"
.endif
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
