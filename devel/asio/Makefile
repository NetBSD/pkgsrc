# $NetBSD: Makefile,v 1.3 2016/10/02 22:04:37 prlw1 Exp $

DISTNAME=	asio-1.10.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=asio/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://think-async.com/
COMMENT=	Library for asynchronous programming
LICENSE=	boost-license

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
