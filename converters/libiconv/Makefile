# $NetBSD: Makefile,v 1.69 2023/01/23 15:22:24 wiz Exp $

DISTNAME=	libiconv-1.17
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GNU:=libiconv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libiconv/
COMMENT=	Character set conversion library
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2.1

USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pax
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no	# has multiple configure scripts

CONFLICTS=	man-pages-[0-9]*

MAKE_JOBS_SAFE=	no

# Explicitly disable NLS since libiconv is a dependency for gettext-lib
# and we don't want libiconv to pick up any NLS functions from libc
# if they exist.
#
CONFIGURE_ARGS+=	--disable-nls

CONFIGURE_ARGS+=	--htmldir=${PREFIX}/share/doc/libiconv

# Explicitly override iconv checks, as GNU libiconv will change its own
# signature based on whether it finds itself already installed somewhere
# which then breaks software (e.g. QT) which assumes the native signature.
#
# Restricted to SunOS for now, but likely will be useful everywhere.
#
CONFIGURE_ENV.SunOS+=	am_cv_func_iconv=yes
CONFIGURE_ENV.SunOS+=	am_cv_proto_iconv_arg1='const'
CONFIGURE_ENV.SunOS+=	am_cv_proto_iconv='extern size_t iconv (iconv_t cd, const char * *inbuf, size_t *inbytesleft, char * *outbuf, size_t *outbytesleft);'

TEST_TARGET=		check

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mmipspro*)
CFLAGS+=		-c99
.endif

.include "../../mk/bsd.pkg.mk"
