# $NetBSD: Makefile,v 1.73 2018/10/13 23:23:20 leot Exp $

DISTNAME=	libtasn1-4.13
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GNU:=libtasn1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libtasn1/
COMMENT=	ASN.1 structure parser library
LICENSE=	gnu-fdl-v1.3 AND gnu-lgpl-v2.1 AND gnu-gpl-v3

USE_LIBTOOL=		yes
USE_TOOLS+=		bison makeinfo
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-packager="pkgsrc"
CONFIGURE_ARGS+=	--with-packager-version="${PKGVERSION}"
CONFIGURE_ARGS+=	--with-packager-bug-reports="http://gnats.NetBSD.org/"
# Mac OS X has no prototype for getopt_long and no declaration for
# struct option, so ignore getopt_long() even though the test succeeds.
CONFIGURE_ENV.Darwin+=	ac_cv_func_getopt_long=no

CFLAGS.Darwin+=		-fno-common
TEST_TARGET=		check
INFO_FILES=		yes
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
