# $NetBSD: Makefile,v 1.18 2016/02/16 15:02:45 taca Exp $

DISTNAME=	flexmock-2.0.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/doudou/flexmock
COMMENT=	Flexible mock object library for Ruby unit testing
LICENSE=	isc

pre-configure:
	find ${WRKSRC}/doc -type f -exec chmod -x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
