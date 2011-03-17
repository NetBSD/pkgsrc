# $NetBSD: Makefile,v 1.7 2011/03/17 21:50:09 zafer Exp $
#

DISTNAME=	httptunnel-3.0.5
CATEGORIES=	net
MASTER_SITES=	http://www.nocrew.org/software/httptunnel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nocrew.org/software/httptunnel.html
COMMENT=	Encapsulate TCP/IP connections in HTTP requests

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

.include "../../mk/bsd.pkg.mk"
