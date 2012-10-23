# $NetBSD: Makefile,v 1.8 2012/10/23 19:51:15 asau Exp $

DISTNAME=		bluez-hcidump-2.4
PKGNAME=		${DISTNAME:S/bluez/netbt/}
CATEGORIES=		sysutils
MASTER_SITES=		http://www.kernel.org/pub/linux/bluetooth/

MAINTAINER=		plunky@rya-online.net
HOMEPAGE=		http://www.bluez.org/
COMMENT=		Bluetooth packet analyzer (netbt version)
LICENSE=		gnu-gpl-v2

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*
CONFLICTS+=		hcidump-[0-9]* bluez-hcidump-[0-9]*

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

CPPFLAGS+=	-DVERSION=\""${DISTNAME:S/bluez-hcidump-//}-netbt"\"

USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.pkg.mk"
