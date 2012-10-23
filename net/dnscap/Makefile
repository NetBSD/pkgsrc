# $NetBSD: Makefile,v 1.2 2012/10/23 17:18:17 asau Exp $

DISTNAME=		dnscap-134
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
