# $NetBSD: Makefile,v 1.6 2009/03/22 04:53:40 manu Exp $
#

DISTNAME=	httptunnel-3.0.5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nocrew.org/pub/nocrew/unix/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nocrew.org/software/httptunnel.html
COMMENT=	Encapsulate TCP/IP connections in HTTP requests

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

.include "../../mk/bsd.pkg.mk"
