# $NetBSD: Makefile,v 1.15 2015/10/07 23:16:09 joerg Exp $

DISTNAME=	flexmock-2.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/doudou/flexmock
COMMENT=	Flexible mock object library for Ruby unit testing
LICENSE=	isc

RUBY_VERSION_SUPPORTED= 200 21 22

pre-configure:
	find ${WRKSRC}/doc -type f -exec chmod -x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
