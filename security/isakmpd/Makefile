# $NetBSD: Makefile,v 1.3 2000/04/25 19:10:11 thorpej Exp $
#

DISTNAME=		isakmpd-000220
PKGNAME=		isakmpd-20000220
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.appli.se/pub/isakmpd/

PATCH_SITES=		ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=		isakmpd-20000220-20000328a.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		itojun@kame.net

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netinet6/ipsec.h)
IGNORE+=		"requires ipsec-ready NetBSD"
.endif

# if PATENTEDOPENSSLSRC is defined, then we assume that
# RSA already exists in the OpenSSL built as part of the
# base distribution.
.if !defined(PATENTEDOPENSSLSRC)
DEPENDS+=		openssl-0.9.4:../../security/openssl
.endif
DEPENDS+=		gmp-*:../../devel/gmp

RESTRICTED=		"Crypto; export-controlled"
MIRROR_DISTFILE=	no

ALL_TARGET=		depend all

.include "../../mk/bsd.pkg.mk"
