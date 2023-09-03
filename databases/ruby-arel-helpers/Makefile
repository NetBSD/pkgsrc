# $NetBSD: Makefile,v 1.11 2023/09/03 15:42:31 taca Exp $

DISTNAME=	arel-helpers-2.14.0
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/camertron/arel-helpers
COMMENT=	Tools to help construct database queries
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
