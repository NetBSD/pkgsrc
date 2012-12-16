# $NetBSD: Makefile,v 1.9 2012/12/16 16:19:51 taca Exp $

DISTNAME=	flexmock-1.2.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flexmock.rubyforge.org/
COMMENT=	Flexible mock object library for Ruby unit testing
LICENSE=	isc

pre-configure:
	find ${WRKSRC}/doc -type f -exec chmod -x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
