# $NetBSD: Makefile,v 1.6 2021/01/13 15:08:19 taca Exp $

DISTNAME=	xdr-3.0.2
CATEGORIES=	net

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/stellar/ruby-xdr
COMMENT=	XDR helper library for Ruby
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
#DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	52 60

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
