# $NetBSD: Makefile,v 1.4 1998/04/15 10:38:36 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1997/06/03 21:52:01 asami Exp
#

DISTNAME=	most4.7
PKGNAME=	most-4.7
CATEGORIES=	misc
MASTER_SITES=	ftp://space.mit.edu/pub/davis/most/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/most/

MAINTAINER=	rhwang@bigpanda.com

LIB_DEPENDS=	slang.0.99[0-9][0-9]:${PORTSDIR}/devel/libslang

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/most
MAN1=		most.1

.include "../../mk/bsd.pkg.mk"
