# $NetBSD: Makefile,v 1.28 2022/02/12 07:25:26 taca Exp $

DISTNAME=	ZenTest-4.12.1
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
