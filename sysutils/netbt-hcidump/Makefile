# $NetBSD: Makefile,v 1.11 2015/03/19 19:16:31 joerg Exp $

DISTNAME=		bluez-5.27
PKGNAME=		netbt-hcidump-${BLUEZ_VERSION}
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.kernel.org/pub/linux/bluetooth/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		plunky@NetBSD.org
HOMEPAGE=		http://www.bluez.org/
COMMENT=		Bluetooth packet analyzer (netbt version)
LICENSE=		gnu-gpl-v2

BLUEZ_VERSION=		${DISTNAME:S/bluez-//}

EXTRACT_USING=		bsdtar

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*
CONFLICTS+=		hcidump-[0-9]* bluez-hcidump-[0-9]*

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CPPFLAGS+=		-DVERSION=\""${BLUEZ_VERSION}-netbt"\"

USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.pkg.mk"
