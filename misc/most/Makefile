# $NetBSD: Makefile,v 1.6 1998/06/22 12:52:33 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1997/06/03 21:52:01 asami Exp
#

DISTNAME=	most4.7
PKGNAME=	most-4.7
CATEGORIES=	misc
MASTER_SITES=	ftp://space.mit.edu/pub/davis/most/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/most/

MAINTAINER=	rhwang@bigpanda.com

DEPENDS+=	libslang-0.99.38:../../devel/libslang

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/most

.include "../../mk/bsd.pkg.mk"
