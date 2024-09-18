# $NetBSD: Makefile,v 1.26 2024/09/18 15:09:33 taca Exp $

DISTNAME=	flexmock-3.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/doudou/flexmock
COMMENT=	Flexible mock object library for Ruby unit testing
LICENSE=	mit

pre-configure:
	find ${WRKSRC}/doc -type f -exec chmod a-x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
