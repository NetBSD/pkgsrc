# $NetBSD: Makefile,v 1.4 2014/02/12 23:18:21 tron Exp $

DISTNAME=	kdnssd-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	net
COMMENT=	Monitors the network for DNS-SD services

.include "../../meta-pkgs/kde4/Makefile.kde4"

# for kded_dnssdwatcher
UNLIMIT_RESOURCES+=	datasize memorysize stacksize

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
