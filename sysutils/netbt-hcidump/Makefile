# $NetBSD: Makefile,v 1.1.1.1 2010/12/19 20:20:42 plunky Exp $

DISTNAME=		netbt-hcidump-1.42
CATEGORIES=		sysutils
MASTER_SITES=		http://bluez.sourceforge.net/download/	\
			http://www.kernel.org/pub/linux/bluetooth/
DISTFILES=		bluez-hcidump-1.42.tar.gz	\
			bluez-4.81.tar.gz

MAINTAINER=		plunky@rya-online.net
HOMEPAGE=		http://www.bluez.org/
COMMENT=		Bluetooth packet analyzer (netbt version)

LICENSE=		gnu-gpl-v2

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*
CONFLICTS+=		hcidump-[0-9]* bluez-hcidump-[0-9]*

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

WRKSRC=			${WRKDIR}/bluez-hcidump-1.42
LIBSRC=			${WRKDIR}/bluez-4.81

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

CPPFLAGS+=	-DVERSION=\""1.42-netbt"\"

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
