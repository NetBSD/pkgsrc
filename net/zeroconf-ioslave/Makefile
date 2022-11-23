# $NetBSD: Makefile,v 1.32 2022/11/23 16:20:56 adam Exp $

DISTNAME=	zeroconf-ioslave-${_KDE_VERSION}
PKGREVISION=	31
CATEGORIES=	net
COMMENT=	Monitors the network for DNS-SD services (Zeroconf)

.include "../../meta-pkgs/kde4/Makefile.kde4"

# for kded_dnssdwatcher
UNLIMIT_RESOURCES+=	datasize memorysize stacksize

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
