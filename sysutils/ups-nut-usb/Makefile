# $NetBSD: Makefile,v 1.15 2022/06/28 11:36:06 wiz Exp $

PKGREVISION= 1
.include "../../sysutils/ups-nut/Makefile.common"

PKGNAME=		${DISTNAME:S/nut/ups-nut-usb/}
COMMENT=		Network UPS Tools USB drivers

DEPENDS+=		ups-nut-2.*:../../sysutils/ups-nut

INSTALLATION_DIRS+=	${PREFIX}/libexec/nut
INSTALLATION_DIRS+=	${PREFIX}/${PKGMANDIR}/man8

BUILD_DEFS+=		NUT_STATEDIR

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--with-usb --with-drvpath=${NUT_DRVDIR:Q}

do-install:
	for f in usbhid-ups bcmxcp_usb tripplite_usb blazer_usb richcomm_usb;\
	 do \
		${INSTALL_PROGRAM} ${WRKSRC}/drivers/$$f \
		    ${DESTDIR}${PREFIX}/libexec/nut/; \
	done
	for f in usbhid-ups.8 bcmxcp_usb.8 tripplite_usb.8 richcomm_usb.8; do \
		${INSTALL_MAN} ${WRKSRC}/docs/man/$$f \
		    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/; \
	done

.include "../../mk/libusb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
