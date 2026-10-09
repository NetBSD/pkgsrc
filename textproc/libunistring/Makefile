# $NetBSD: Makefile,v 1.23 2026/10/09 12:02:00 tnn Exp $

DISTNAME=	libunistring-1.4.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=libunistring/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libunistring/
COMMENT=	Unicode string library
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 # or-later in both cases

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INFO_FILES=	yes
TEST_TARGET=	check

# Upstream insists on enforcing GNU iconv on macOS.
CONFIGURE_ENV.Darwin+=	am_cv_func_iconv_works=yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
