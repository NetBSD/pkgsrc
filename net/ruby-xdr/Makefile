# $NetBSD: Makefile,v 1.3 2020/03/21 20:26:17 tnn Exp $

DISTNAME=	xdr-3.0.0
CATEGORIES=	net

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/stellar/ruby-xdr
COMMENT=	XDR helper library for Ruby
LICENSE=	apache-2.0

#DEPENDS+=	${RUBY_PKGPREFIX}-activemodel42>=4.2.7:../../devel/ruby-activemodel42
#DEPENDS+=	${RUBY_PKGPREFIX}-activesupport42>=4.2.7:../../devel/ruby-activesupport42
BROKEN=		"rails 4.2 was removed"

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
