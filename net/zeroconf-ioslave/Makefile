# $NetBSD: Makefile,v 1.44 2024/11/01 12:54:05 wiz Exp $

DISTNAME=	zeroconf-ioslave-${_KDE_VERSION}
PKGREVISION=	43
CATEGORIES=	net
COMMENT=	Monitors the network for DNS-SD services (Zeroconf)

.include "../../meta-pkgs/kde4/Makefile.kde4"

# for kded_dnssdwatcher
UNLIMIT_RESOURCES+=	datasize memorysize stacksize

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
