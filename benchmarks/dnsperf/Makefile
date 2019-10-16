# $NetBSD: Makefile,v 1.10 2019/10/16 09:37:27 maya Exp $

DISTNAME=	dnsperf-src-2.1.0.0-1
PKGNAME=	dnsperf-2.1.0.0
PKGREVISION=	2
CATEGORIES=	benchmarks net
MASTER_SITES=	ftp://ftp.nominum.com/pub/nominum/${PKGBASE}/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nominum.com/support/measurement-tools/
COMMENT=	DNS server performance measurement tools
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	sh:run

# This package needs "isc" include files and "isc-config.sh" to build.
# The built-in check only considers "libbind".
USE_BUILTIN.bind=	no

REPLACE_SH+=	resperf-report

.include "../../archivers/xz/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../net/bind914/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
