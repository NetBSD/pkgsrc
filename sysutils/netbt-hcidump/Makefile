# $NetBSD: Makefile,v 1.9 2012/12/12 11:32:08 plunky Exp $

DISTNAME=		bluez-hcidump-2.5
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
