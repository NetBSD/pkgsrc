# $NetBSD: Makefile,v 1.26 2019/11/03 10:39:05 rillig Exp $

DISTNAME=	ZenTest-4.12.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.zenspider.com/ZSS/Products/ZenTest/
COMMENT=	Testing utilities for Ruby
LICENSE=	mit

CONFLICTS+=		ruby[1-9][0-9][0-9]-ZenTest-[0-9]* ZenTest-[0-9]*
RUBYGEM_OPTIONS+=	--format-executable

USE_LANGUAGES=	# empty

pre-configure:
	${CHMOD} ${BINMODE} ${WRKSRC}/bin/*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
