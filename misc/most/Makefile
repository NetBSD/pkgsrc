# $NetBSD: Makefile,v 1.14 2001/04/20 22:20:50 jtb Exp $
# FreeBSD Id: Makefile,v 1.2 1997/06/03 21:52:01 asami Exp
#

DISTNAME=	most-4.9.0
CATEGORIES=	misc
MASTER_SITES=	ftp://space.mit.edu/pub/davis/most/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/most/

MAINTAINER=	rhwang@bigpanda.com
HOMEPAGE=	http://space.mit.edu/~davis/most.html
COMMENT=	Pager (like less) which has support for windows and binary files

DEPENDS+=	libslang-*:../../devel/libslang

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-x

.include "../../mk/bsd.pkg.mk"
