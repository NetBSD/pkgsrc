# $NetBSD: Makefile,v 1.27 2021/05/21 16:44:00 nia Exp $

DISTNAME=	ZenTest-4.12.0
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
