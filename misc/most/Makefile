# $NetBSD: Makefile,v 1.30 2016/02/25 15:35:30 jperkin Exp $

DISTNAME=	most-5.0.0a
PKGREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	ftp://space.mit.edu/pub/davis/most/

MAINTAINER=	rhwang@bigpanda.com
HOMEPAGE=	http://www.jedsoft.org/most/
COMMENT=	Pager (like less) which has support for windows and binary files

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-x

CONFIGURE_ARGS+=	--with-slang=${BUILDLINK_PREFIX.libslang2}

# prevent duplicate definition of zopen
CFLAGS.Darwin+=	-D_POSIX_C_SOURCE

.include "../../devel/libslang2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
