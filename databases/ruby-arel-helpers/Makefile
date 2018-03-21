# $NetBSD: Makefile,v 1.3 2018/03/21 10:21:20 taca Exp $

DISTNAME=	arel-helpers-2.6.1
CATEGORIES=	databases

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/camertron/arel-helpers
COMMENT=	Tools to help construct database queries
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}

RUBY_RAILS_ACCEPTED=	42 51

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
