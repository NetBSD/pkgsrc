# $NetBSD: Makefile,v 1.8 1998/08/20 15:17:14 tsarna Exp $
# FreeBSD Id: Makefile,v 1.2 1997/06/03 21:52:01 asami Exp
#

DISTNAME=	most4.8.1
PKGNAME=	most-4.8.1
CATEGORIES=	misc
MASTER_SITES=	ftp://space.mit.edu/pub/davis/most/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/most/

MAINTAINER=	rhwang@bigpanda.com
HOMEPAGE=	http://space.mit.edu/~davis/most.html

DEPENDS+=	libslang-1.2.2:../../devel/libslang

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-x
WRKSRC=		${WRKDIR}/most

.include "../../mk/bsd.pkg.mk"
