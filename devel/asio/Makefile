# $NetBSD: Makefile,v 1.5 2020/01/18 21:48:02 jperkin Exp $

DISTNAME=	asio-1.10.8
PKGREVISION=	2
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
