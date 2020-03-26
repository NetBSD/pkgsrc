# $NetBSD: Makefile,v 1.79 2020/03/26 12:00:45 nia Exp $

DISTNAME=	libtasn1-4.16.0
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GNU:=libtasn1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libtasn1/
COMMENT=	ASN.1 structure parser library
LICENSE=	gnu-fdl-v1.3 AND gnu-lgpl-v2.1 AND gnu-gpl-v3

USE_LIBTOOL=		yes
USE_TOOLS+=		bison makeinfo
USE_LANGUAGES=		c99
GNU_CONFIGURE=		yes

# Mac OS X has no prototype for getopt_long and no declaration for
# struct option, so ignore getopt_long() even though the test succeeds.
CONFIGURE_ENV.Darwin+=	ac_cv_func_getopt_long=no

CFLAGS.Darwin+=		-fno-common
TEST_TARGET=		check
INFO_FILES=		yes

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
