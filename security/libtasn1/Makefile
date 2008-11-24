# $NetBSD: Makefile,v 1.38 2008/11/24 15:36:03 adam Exp $

DISTNAME=	libtasn1-1.7
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GNU:=gnutls/} \
		ftp://ftp.gnutls.org/pub/gnutls/libtasn1/ \
		ftp://ftp.gnupg.org/gcrypt/alpha/gnutls/libtasn1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	ASN.1 structure parser library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		makeinfo
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check
INFO_FILES=		yes
#LICENSE=		gnu-lgpl-v2.1 and gnu-gpl-3.0

.include "../../mk/bsd.prefs.mk"

# Darwin has no prototype for getopt_long and no declaration for
# struct option, so ignore getopt_long() even though the test succeeds.
.if ${OPSYS} == "Darwin"
CONFIGURE_ENV+=		ac_cv_func_getopt_long=no
CFLAGS+=	-fno-common
.endif

.include "../../mk/bsd.pkg.mk"
