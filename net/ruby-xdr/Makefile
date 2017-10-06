# $NetBSD: Makefile,v 1.1 2017/10/06 17:00:29 minskim Exp $

DISTNAME=	xdr-2.0.0
CATEGORIES=	net

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/stellar/ruby-xdr
COMMENT=	XDR helper library for Ruby
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-activemodel42>=4.2.7:../../devel/ruby-activemodel42
DEPENDS+=	${RUBY_PKGPREFIX}-activesupport42>=4.2.7:../../devel/ruby-activesupport42

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
