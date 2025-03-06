# $NetBSD: Makefile,v 1.36 2025/03/06 08:44:41 adam Exp $

DISTNAME=	most-5.2.0
CATEGORIES=	misc
MASTER_SITES=	https://www.jedsoft.org/releases/most/

MAINTAINER=	rhwang@bigpanda.com
HOMEPAGE=	https://www.jedsoft.org/most/
COMMENT=	Pager (like less) which has support for windows and binary files
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--with-slang=${BUILDLINK_PREFIX.libslang}

# prevent duplicate definition of zopen
CFLAGS.Darwin+=	-D_POSIX_C_SOURCE

.include "../../devel/libslang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
