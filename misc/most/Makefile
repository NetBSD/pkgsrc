# $NetBSD: Makefile,v 1.18 2005/12/05 20:50:40 rillig Exp $

DISTNAME=	most-4.9.0
CATEGORIES=	misc
MASTER_SITES=	ftp://space.mit.edu/pub/davis/most/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/most/

MAINTAINER=	rhwang@bigpanda.com
HOMEPAGE=	http://space.mit.edu/~davis/most.html
COMMENT=	Pager (like less) which has support for windows and binary files

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-x

.include "../../devel/libslang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
