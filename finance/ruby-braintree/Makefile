# $NetBSD: Makefile,v 1.5 2021/02/05 16:16:25 taca Exp $

DISTNAME=	braintree-3.2.0
CATEGORIES=	finance

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.braintreepaymentsolutions.com/gateway
COMMENT=	Braintree Gateway Ruby Client Library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.0.0:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-libxml>=3.2.0:../../textproc/ruby-libxml

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
