# $NetBSD: Makefile,v 1.24 2019/01/06 15:00:14 taca Exp $

DISTNAME=	ZenTest-4.11.2
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
