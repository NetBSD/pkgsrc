# $NetBSD: Makefile,v 1.16 2005/03/24 21:12:58 wiz Exp $

DISTNAME=	most-4.9.0
CATEGORIES=	misc
MASTER_SITES=	ftp://space.mit.edu/pub/davis/most/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/most/

MAINTAINER=	rhwang@bigpanda.com
HOMEPAGE=	http://space.mit.edu/~davis/most.html
COMMENT=	Pager (like less) which has support for windows and binary files

DEPENDS+=	libslang-[0-9]*:../../devel/libslang

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-x

.include "../../mk/bsd.pkg.mk"
