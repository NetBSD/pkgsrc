# $NetBSD: Makefile,v 1.3 2013/02/06 19:30:56 jperkin Exp $

DISTNAME=		dnscap-134
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://dnscap.dns-oarc.net/

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		https://www.dns-oarc.net/tools/dnscap
COMMENT=		Network capture utility designed specifically for DNS traffic
LICENSE=		isc

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${MANPREFIX}/man1

.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
