# $NetBSD: Makefile,v 1.11 2022/09/03 14:47:35 taca Exp $

DISTNAME=	stream-0.5.5
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/monora/stream
COMMENT=	Interface for external iterators
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-generator>=0:../../devel/ruby-generator

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
