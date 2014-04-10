# $NetBSD: Makefile,v 1.5 2014/04/10 06:21:34 obache Exp $

DISTNAME=	kdnssd-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	net
COMMENT=	Monitors the network for DNS-SD services

.include "../../meta-pkgs/kde4/Makefile.kde4"

# for kded_dnssdwatcher
UNLIMIT_RESOURCES+=	datasize memorysize stacksize

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
