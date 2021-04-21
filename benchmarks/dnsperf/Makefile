# $NetBSD: Makefile,v 1.20 2021/04/21 11:41:02 adam Exp $

DISTNAME=	dnsperf-2.5.1
PKGREVISION=	1
CATEGORIES=	benchmarks net
MASTER_SITES=	https://www.dns-oarc.net/files/dnsperf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dns-oarc.net/tools/dnsperf
COMMENT=	DNS server performance measurement tools
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	sh:run pkg-config

# This package needs "isc" include files and "isc-config.sh" to build.
# The built-in check only considers "libbind".
USE_BUILTIN.bind=	no

REPLACE_SH+=	src/resperf-report

.include "../../archivers/xz/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/concurrencykit/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../net/bind916/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
