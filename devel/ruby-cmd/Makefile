# $NetBSD: Makefile,v 1.8 2010/09/10 05:13:12 taca Exp $

DISTNAME=	cmd-0.7.2
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/cmd/
COMMENT=	Library for building line-oriented command interpreters
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-readline>=${RUBY_REQD}:../../devel/ruby-readline

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
