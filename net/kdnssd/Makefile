# $NetBSD: Makefile,v 1.8 2014/11/07 19:39:40 adam Exp $

DISTNAME=	kdnssd-${_KDE_VERSION}
PKGREVISION=	5
CATEGORIES=	net
COMMENT=	Monitors the network for DNS-SD services

.include "../../meta-pkgs/kde4/Makefile.kde4"

# for kded_dnssdwatcher
UNLIMIT_RESOURCES+=	datasize memorysize stacksize

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
