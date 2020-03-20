# $NetBSD: Makefile,v 1.6 2020/03/20 15:08:08 taca Exp $

DISTNAME=	arel-helpers-2.11.0
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/camertron/arel-helpers
COMMENT=	Tools to help construct database queries
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	# defined

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
