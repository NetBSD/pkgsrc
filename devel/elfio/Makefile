# $NetBSD: Makefile,v 1.3 2023/07/09 14:03:20 nia Exp $
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

# std::make_unique
GCC_REQD+=	5

.include "../../mk/bsd.pkg.mk"
