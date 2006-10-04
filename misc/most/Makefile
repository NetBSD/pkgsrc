# $NetBSD: Makefile,v 1.20 2006/10/04 21:49:19 wiz Exp $

DISTNAME=	most-4.9.0
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://space.mit.edu/pub/davis/most/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/most/

MAINTAINER=	rhwang@bigpanda.com
HOMEPAGE=	http://www.jedsoft.org/most/
COMMENT=	Pager (like less) which has support for windows and binary files

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-x

.include "../../devel/libslang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
