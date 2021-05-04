# $NetBSD: Makefile,v 1.7 2021/05/04 15:20:44 taca Exp $

DISTNAME=	braintree-3.4.0
CATEGORIES=	finance

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.braintreepaymentsolutions.com/gateway
COMMENT=	Braintree Gateway Ruby Client Library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-builder>=3.2.4:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-libxml>=3.2.0:../../textproc/ruby-libxml

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
