# $NetBSD: Makefile,v 1.13 2014/03/14 15:36:16 taca Exp $

DISTNAME=	flexmock-1.3.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jimweirich/flexmock
COMMENT=	Flexible mock object library for Ruby unit testing
LICENSE=	isc

pre-configure:
	find ${WRKSRC}/doc -type f -exec chmod -x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
