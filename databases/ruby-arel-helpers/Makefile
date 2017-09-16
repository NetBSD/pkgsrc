# $NetBSD: Makefile,v 1.2 2017/09/16 08:53:47 wiz Exp $

DISTNAME=	arel-helpers-2.4.0
CATEGORIES=	databases

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/camertron
COMMENT=	Tools to help construct database queries

DEPENDS+=	${RUBY_PKGPREFIX}-activerecord42>=3.1.0<6:../../databases/ruby-activerecord42

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
