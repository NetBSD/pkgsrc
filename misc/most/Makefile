# $NetBSD: Makefile,v 1.22 2007/02/10 04:53:08 obache Exp $

DISTNAME=	most-4.9.0
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://space.mit.edu/pub/davis/most/

MAINTAINER=	rhwang@bigpanda.com
HOMEPAGE=	http://www.jedsoft.org/most/
COMMENT=	Pager (like less) which has support for windows and binary files

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-x

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
# prevent duplicate definition of zopen
CFLAGS+= -D_POSIX_C_SOURCE
.endif

.include "../../devel/libslang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
