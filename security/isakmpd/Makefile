# $NetBSD: Makefile,v 1.7 2000/08/21 21:01:33 hubertf Exp $
#

BROKEN=			"broken by PF_KEY API change"

DISTNAME=		isakmpd-000220
PKGNAME=		isakmpd-20000220
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.appli.se/pub/isakmpd/

PATCH_SITES=		ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=		isakmpd-20000220-20000427a.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		itojun@kame.net

RESTRICTED=		"Crypto; export-controlled"

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netinet6/ipsec.h)
IGNORE+=		"${PKGNAME} requires ipsec-ready NetBSD"
.endif

# if PATENTEDOPENSSLSRC is defined, then we assume that
# RSA already exists in the OpenSSL built as part of the
# base distribution.
.if !defined(PATENTEDOPENSSLSRC)
DEPENDS+=		openssl-0.9.*:../../security/openssl
.endif
DEPENDS+=		gmp-*:../../devel/gmp

RESTRICTED=		"Crypto; export-controlled"
NO_SRC_ON_FTP=		${RESTRICTED}

ALL_TARGET=		depend all

.include "../../mk/bsd.pkg.mk"
