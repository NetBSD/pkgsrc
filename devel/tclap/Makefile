# $NetBSD: Makefile,v 1.7 2025/11/17 11:00:41 wiz Exp $

DISTNAME=	tclap-1.2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tclap/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://tclap.sourceforge.net/
COMMENT=	Templatized C++ Command Line Parser Library
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
