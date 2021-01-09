# $NetBSD: Makefile,v 1.6 2021/01/09 21:14:19 adam Exp $

DISTNAME=	tclap-1.2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tclap/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://tclap.sourceforge.net/
COMMENT=	Templatized C++ Command Line Parser Library
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
