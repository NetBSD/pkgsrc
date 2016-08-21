# $NetBSD: Makefile,v 1.23 2016/08/21 08:31:41 taca Exp $

DISTNAME=	ZenTest-4.11.1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.zenspider.com/ZSS/Products/ZenTest/
COMMENT=	Testing utilities for Ruby
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9][0-9]-ZenTest-[0-9]* ZenTest-[0-9]*
RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	${CHMOD} ${BINMODE} ${WRKSRC}/bin/*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
