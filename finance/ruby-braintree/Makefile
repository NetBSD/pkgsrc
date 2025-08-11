# $NetBSD: Makefile,v 1.30 2025/08/11 15:11:45 taca Exp $

DISTNAME=	braintree-4.30.0
CATEGORIES=	finance

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.braintreepaymentsolutions.com/gateway
COMMENT=	Braintree Gateway Ruby Client Library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-builder>=3.2.4:../../textproc/ruby-builder

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
