# $NetBSD: Makefile,v 1.7 2026/10/07 20:58:45 agc Exp $

DISTNAME=		dnscap-2.5.2
PKGNAME=		dnscap2-2.5.2
CATEGORIES=		net
MASTER_SITES=		https://www.dns-oarc.net/files/dnscap/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.dns-oarc.net/tools/dnscap
COMMENT=		Network capture utility designed specifically for DNS traffic
LICENSE=		isc

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

USE_TOOLS+=		pkg-config perl

REPLACE_PERL=		plugins/rssm/dnscap-rssm-rssac002

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../net/ldns/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
