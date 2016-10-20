# $NetBSD: Makefile,v 1.21 2016/10/20 14:36:17 taca Exp $

DISTNAME=	flexmock-2.3.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/doudou/flexmock
COMMENT=	Flexible mock object library for Ruby unit testing
LICENSE=	isc

pre-configure:
	find ${WRKSRC}/doc -type f -exec chmod a-x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
