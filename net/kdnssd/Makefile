# $NetBSD: Makefile,v 1.7 2014/08/22 11:24:41 wiz Exp $

DISTNAME=	kdnssd-${_KDE_VERSION}
PKGREVISION=	4
CATEGORIES=	net
COMMENT=	Monitors the network for DNS-SD services

.include "../../meta-pkgs/kde4/Makefile.kde4"

# for kded_dnssdwatcher
UNLIMIT_RESOURCES+=	datasize memorysize stacksize

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
