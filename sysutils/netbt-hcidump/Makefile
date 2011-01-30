# $NetBSD: Makefile,v 1.2 2011/01/30 20:41:29 plunky Exp $

DISTNAME=		netbt-hcidump-2.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.kernel.org/pub/linux/bluetooth/
DISTFILES=		bluez-hcidump-2.0.tar.gz	\
			bluez-4.87.tar.gz

MAINTAINER=		plunky@rya-online.net
HOMEPAGE=		http://www.bluez.org/
COMMENT=		Bluetooth packet analyzer (netbt version)
LICENSE=		gnu-gpl-v2

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*
CONFLICTS+=		hcidump-[0-9]* bluez-hcidump-[0-9]*

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

WRKSRC=			${WRKDIR}/bluez-hcidump-2.0
LIBSRC=			${WRKDIR}/bluez-4.87

PKG_DESTDIR_SUPPORT=	user-destdir

CPPFLAGS+=	-DVERSION=\""2.0-netbt"\"

USE_BSD_MAKEFILE=	yes

post-extract:
	mkdir ${WRKSRC}/bluetooth
	cp ${LIBSRC}/lib/bluetooth.h ${WRKSRC}/bluetooth
	cp ${LIBSRC}/lib/hci.h ${WRKSRC}/bluetooth
	cp ${LIBSRC}/lib/hci_lib.h ${WRKSRC}/bluetooth
	cp ${LIBSRC}/lib/l2cap.h ${WRKSRC}/bluetooth
	cp ${LIBSRC}/lib/bluetooth.c ${WRKSRC}/src/bt_lib.c
	cp ${LIBSRC}/lib/hci.c ${WRKSRC}/src/hci_lib.c

.include "../../mk/bsd.pkg.mk"
