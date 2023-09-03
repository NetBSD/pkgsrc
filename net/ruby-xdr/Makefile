# $NetBSD: Makefile,v 1.8 2023/09/03 15:42:32 taca Exp $

DISTNAME=	xdr-3.0.3
PKGREVISION=	1
CATEGORIES=	net

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/stellar/ruby-xdr
COMMENT=	XDR helper library for Ruby
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
#DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
