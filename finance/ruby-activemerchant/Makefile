# $NetBSD: Makefile,v 1.4 2011/06/19 08:15:29 taca Exp $

DISTNAME=	activemerchant-1.15.0
CATEGORIES=	finance

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://activemerchant.org/
COMMENT=	Ruby library for credit card processing
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.3.8:../../devel/ruby-activesupport
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.0.0:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-braintree>=2.0.0:../../finance/ruby-braintree

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
