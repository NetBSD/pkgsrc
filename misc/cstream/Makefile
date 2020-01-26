# $NetBSD: Makefile,v 1.13 2020/01/26 17:31:43 rillig Exp $

DISTNAME=	cstream-3.1.1
CATEGORIES=	misc
MASTER_SITES=	http://www.cons.org/cracauer/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cons.org/cracauer/cstream.html
COMMENT=	General-purpose stream-handling tool with bandwidth limiting
LICENSE=	x11

GNU_CONFIGURE=	yes

LDFLAGS.SunOS+=	-lsocket -lnsl -lresolv

.include "../../mk/bsd.pkg.mk"
