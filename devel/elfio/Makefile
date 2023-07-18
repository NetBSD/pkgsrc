# $NetBSD: Makefile,v 1.4 2023/07/18 14:11:15 nia Exp $
#

DISTNAME=	elfio-3.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=elfio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://elfio.sourceforge.net/
COMMENT=	C++ library for reading and generating ELF files
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	unique_ptr

.include "../../mk/bsd.pkg.mk"
