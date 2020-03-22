# $NetBSD: Makefile,v 1.4 2020/03/22 03:52:45 taca Exp $

DISTNAME=	xdr-3.0.0
PKGREVISION=	1
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
