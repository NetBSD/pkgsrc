# $NetBSD: Makefile,v 1.10 2021/11/23 14:24:37 taca Exp $

DISTNAME=	braintree-4.5.0
CATEGORIES=	finance

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.braintreepaymentsolutions.com/gateway
COMMENT=	Braintree Gateway Ruby Client Library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-builder>=3.2.4:../../textproc/ruby-builder

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
