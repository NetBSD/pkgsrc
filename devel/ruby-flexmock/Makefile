# $NetBSD: Makefile,v 1.16 2015/11/29 13:58:32 taca Exp $

DISTNAME=	flexmock-2.0.2
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
