# $NetBSD: Makefile,v 1.35 2025/01/06 21:49:22 ktnb Exp $

DISTNAME=	most-5.1.0
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	https://www.jedsoft.org/releases/most/

MAINTAINER=	rhwang@bigpanda.com
HOMEPAGE=	https://www.jedsoft.org/most/
COMMENT=	Pager (like less) which has support for windows and binary files
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-x

CONFIGURE_ARGS+=	--with-slang=${BUILDLINK_PREFIX.libslang}

# prevent duplicate definition of zopen
CFLAGS.Darwin+=	-D_POSIX_C_SOURCE

.include "../../devel/libslang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
