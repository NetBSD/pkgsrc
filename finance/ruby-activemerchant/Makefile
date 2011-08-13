# $NetBSD: Makefile,v 1.5 2011/08/13 01:05:17 taca Exp $

DISTNAME=	activemerchant-1.16.0
CATEGORIES=	finance

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://activemerchant.org/
COMMENT=	Ruby library for credit card processing
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.0.0:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-braintree>=2.0.0:../../finance/ruby-braintree
DEPENDS+=	${RUBY_PKGPREFIX}-json>=1.5.1:../../textproc/ruby-json

RUBY_RAILS=	2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
