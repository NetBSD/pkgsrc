# $NetBSD: Makefile,v 1.5 2010/12/04 03:58:30 taca Exp $

DISTNAME=	flexmock-0.8.11
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flexmock.rubyforge.org/
COMMENT=	Flexible mock object library for Ruby unit testing
LICENSE=	isc

pre-configure:
	find ${WRKSRC}/doc -type f -exec chmod -x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
