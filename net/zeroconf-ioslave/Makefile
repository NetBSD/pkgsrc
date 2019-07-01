# $NetBSD: Makefile,v 1.14 2019/07/01 04:08:43 ryoon Exp $

DISTNAME=	zeroconf-ioslave-${_KDE_VERSION}
PKGREVISION=	13
CATEGORIES=	net
COMMENT=	Monitors the network for DNS-SD services (Zeroconf)

.include "../../meta-pkgs/kde4/Makefile.kde4"

# for kded_dnssdwatcher
UNLIMIT_RESOURCES+=	datasize memorysize stacksize

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
