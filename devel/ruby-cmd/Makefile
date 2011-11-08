# $NetBSD: Makefile,v 1.9 2011/11/08 15:42:27 taca Exp $

DISTNAME=	cmd-0.7.2
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/cmd/
COMMENT=	Library for building line-oriented command interpreters
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-readline>=${RUBY_VERSION}:../../devel/ruby-readline

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
