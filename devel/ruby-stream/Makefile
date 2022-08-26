# $NetBSD: Makefile,v 1.10 2022/08/26 11:35:45 taca Exp $

DISTNAME=	stream-0.5.4
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/monora/stream
COMMENT=	Interface for external iterators
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-generator>=0:../../devel/ruby-generator

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
