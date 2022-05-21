# $NetBSD: Makefile,v 1.33 2022/05/21 21:38:36 fcambus Exp $

DISTNAME=	most-5.1.0
CATEGORIES=	misc
MASTER_SITES=	https://www.jedsoft.org/releases/most/

MAINTAINER=	rhwang@bigpanda.com
HOMEPAGE=	https://www.jedsoft.org/most/
COMMENT=	Pager (like less) which has support for windows and binary files

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-x

CONFIGURE_ARGS+=	--with-slang=${BUILDLINK_PREFIX.libslang2}

# prevent duplicate definition of zopen
CFLAGS.Darwin+=	-D_POSIX_C_SOURCE

.include "../../devel/libslang2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
