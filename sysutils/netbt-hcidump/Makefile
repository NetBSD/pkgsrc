# $NetBSD: Makefile,v 1.4.6.2 2012/02/15 09:26:54 plunky Exp $

DISTNAME=		netbt-hcidump-2.1
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.kernel.org/pub/linux/bluetooth/
DISTFILES=		bluez-hcidump-2.1.tar.gz	\
			bluez-4.94.tar.gz

MAINTAINER=		plunky@rya-online.net
HOMEPAGE=		http://www.bluez.org/
COMMENT=		Bluetooth packet analyzer (netbt version)
LICENSE=		gnu-gpl-v2

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*
CONFLICTS+=		hcidump-[0-9]* bluez-hcidump-[0-9]*

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

WRKSRC=			${WRKDIR}/bluez-hcidump-2.1
LIBSRC=			${WRKDIR}/bluez-4.94

PKG_DESTDIR_SUPPORT=	user-destdir

CPPFLAGS+=	-DVERSION=\""2.1-netbt"\"

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
