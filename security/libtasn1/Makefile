# $NetBSD: Makefile,v 1.65 2016/02/26 09:41:05 jperkin Exp $

DISTNAME=	libtasn1-4.5
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GNU:=libtasn1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libtasn1/
COMMENT=	ASN.1 structure parser library
LICENSE=	gnu-fdl-v1.3 AND gnu-lgpl-v2.1 AND gnu-gpl-v3

USE_TOOLS+=		makeinfo
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check
INFO_FILES=		yes

CONFIGURE_ARGS+=	--with-packager="pkgsrc"
CONFIGURE_ARGS+=	--with-packager-version="${PKGVERSION}"
CONFIGURE_ARGS+=	--with-packager-bug-reports="http://gnats.NetBSD.org/"

# Mac OS X has no prototype for getopt_long and no declaration for
# struct option, so ignore getopt_long() even though the test succeeds.
CONFIGURE_ENV.Darwin+=	ac_cv_func_getopt_long=no
CFLAGS.Darwin+=		-fno-common

.include "../../mk/bsd.pkg.mk"
