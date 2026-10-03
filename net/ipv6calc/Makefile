# $NetBSD: Makefile,v 1.41 2026/10/03 18:40:36 drixter Exp $

DISTNAME=	ipv6calc-4.4.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=pbiering/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://www.deepspace6.net/projects/ipv6calc.html
COMMENT=	Manipulates IPv6 addresses
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
USE_TOOLS+=	perl
USE_TOOLS+=	bash

MAKE_FLAGS+=	CFLAGS="${CFLAGS} -Wno-error=char-subscripts -Wno-char-subscripts"

REPLACE_PERL+=	tools/ipv6calc-create-registry-list-ipv4.pl
REPLACE_PERL+=	tools/ipv6calc-create-registry-list-ipv6.pl

REPLACE_BASH+=	ipv6calcweb/create_ipv6calcweb-cgi.sh
REPLACE_BASH+=	tools/DBIP-update.sh.in
REPLACE_BASH+=	tools/GeoIP-update.sh.in
REPLACE_BASH+=	tools/IP2Location-update.sh.in
REPLACE_BASH+=	tools/ipv6calc-create-update-ipset.sh
REPLACE_BASH+=	tools/ipv6calc-db-update-support.sh
REPLACE_BASH+=	tools/ipv6calc-db-update.sh.in
REPLACE_BASH+=	tools/ipv6calc-update-registries.sh

.include "../../mk/bsd.pkg.mk"
