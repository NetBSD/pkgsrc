# $NetBSD: Makefile,v 1.3 2014/02/01 02:20:52 markd Exp $

DISTNAME=	kdnssd-${_KDE_VERSION}
CATEGORIES=	net
COMMENT=	Monitors the network for DNS-SD services

.include "../../meta-pkgs/kde4/Makefile.kde4"

# for kded_dnssdwatcher
UNLIMIT_RESOURCES+=	datasize memorysize stacksize

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
