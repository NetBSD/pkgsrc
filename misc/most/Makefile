# $NetBSD: Makefile,v 1.26 2012/01/10 01:45:20 sbd Exp $

DISTNAME=	most-5.0.0a
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	ftp://space.mit.edu/pub/davis/most/

MAINTAINER=	rhwang@bigpanda.com
HOMEPAGE=	http://www.jedsoft.org/most/
COMMENT=	Pager (like less) which has support for windows and binary files

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-x

CONFIGURE_ARGS+=	--with-slang=${BUILDLINK_PREFIX.libslang2}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
# prevent duplicate definition of zopen
CFLAGS+= -D_POSIX_C_SOURCE
.endif

.include "../../devel/libslang2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
