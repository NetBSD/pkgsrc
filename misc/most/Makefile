# $NetBSD: Makefile,v 1.15 2001/09/27 23:18:25 jlam Exp $
# FreeBSD Id: Makefile,v 1.2 1997/06/03 21:52:01 asami Exp
#

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
