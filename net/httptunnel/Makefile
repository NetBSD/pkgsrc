# $NetBSD: Makefile,v 1.5 2008/07/14 12:56:10 joerg Exp $
#

DISTNAME=	httptunnel-3.0.5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nocrew.org/pub/nocrew/unix/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://www.nocrew.org/software/httptunnel.html
COMMENT=	Encapsulate TCP/IP connections in HTTP requests

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

.include "../../mk/bsd.pkg.mk"
