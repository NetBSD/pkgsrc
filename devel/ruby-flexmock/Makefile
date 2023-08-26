# $NetBSD: Makefile,v 1.25 2023/08/26 13:29:48 taca Exp $

DISTNAME=	flexmock-2.3.8
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/doudou/flexmock
COMMENT=	Flexible mock object library for Ruby unit testing
LICENSE=	mit

pre-configure:
	find ${WRKSRC}/doc -type f -exec chmod a-x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
