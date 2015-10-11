# $NetBSD: Makefile,v 1.5 2015/10/11 10:56:43 tron Exp $

DISTNAME=	dnsperf-src-2.0.0.0-1
PKGNAME=	dnsperf-2.0.0.0
PKGREVISION=	1
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

.include "../../net/bind99/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
