# $NetBSD: Makefile,v 1.28 2006/05/17 21:49:54 wiz Exp $

DISTNAME=	libtasn1-0.3.4
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/libtasn1/ \
		ftp://ftp.gnupg.org/gcrypt/alpha/gnutls/libtasn1/ \
		http://www.mirrors.wiretapped.net/security/network-security/gnutls/libtasn1/ \
		ftp://ftp.mirrors.wiretapped.net/pub/security/network-security/gnutls/libtasn1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	ASN.1 structure parser library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		makeinfo
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check
INFO_FILES=		# PLIST

.include "../../mk/bsd.prefs.mk"

# Darwin has no prototype for getopt_long and no declaration for
# struct option, so ignore getopt_long() even though the test
# succeeds.
.if ${OPSYS} == "Darwin"
CONFIGURE_ENV+=		ac_cv_func_getopt_long=no
.endif

.include "../../mk/bsd.pkg.mk"
