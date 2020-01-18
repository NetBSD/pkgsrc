# $NetBSD: Makefile,v 1.4 2020/01/18 23:32:51 rillig Exp $

DISTNAME=	libint-2.0.0-stable
PKGNAME=	libint-2.0.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libint/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://sourceforge.net/p/libint/
COMMENT=	Efficient computation of quantum mechanical matrix elements over Gaussian basis sets

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_TOOLS=	gmake
USE_LIBTOOL=	yes
BUILD_TARGET=	default

.include "../../mk/bsd.pkg.mk"
