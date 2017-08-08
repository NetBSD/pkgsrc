# $NetBSD: Makefile,v 1.5 2017/08/08 16:38:19 jlam Exp $

DISTNAME=		dnscap-141
CATEGORIES=		net
MASTER_SITES=		http://dnscap.dns-oarc.net/

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		https://www.dns-oarc.net/tools/dnscap
COMMENT=		Network capture utility designed specifically for DNS traffic
LICENSE=		isc

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
