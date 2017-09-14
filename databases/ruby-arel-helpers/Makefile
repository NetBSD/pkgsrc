# $NetBSD: Makefile,v 1.1 2017/09/14 19:54:49 minskim Exp $

DISTNAME=	arel-helpers-2.4.0
CATEGORIES=	databases

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://github.com/camertron
COMMENT=	Tools to help construct database queries

DEPENDS+=	${RUBY_PKGPREFIX}-activerecord42>=3.1.0<6:../../databases/ruby-activerecord42

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
