# $NetBSD: Makefile,v 1.2 2024/07/14 07:18:27 taca Exp $

DISTNAME=	ZenTest-4.12.2
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.zenspider.com/ZSS/Products/ZenTest/
COMMENT=	Testing utilities for Ruby
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable

USE_LANGUAGES=	# empty

pre-configure:
	${CHMOD} ${BINMODE} ${WRKSRC}/bin/*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
