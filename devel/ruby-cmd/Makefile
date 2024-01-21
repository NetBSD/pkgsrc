# $NetBSD: Makefile,v 1.12 2024/01/21 09:14:41 taca Exp $

DISTNAME=	cmd-0.7.2
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	# http://rubyforge.org/projects/cmd/
COMMENT=	Library for building line-oriented command interpreters
LICENSE=	mit

OVERRIDE_GEMSPEC=	:files download= rdoc=

.include "../../lang/ruby/rubyversion.mk"
.if ${RUBY_VER} < 33
DEPENDS+=	${RUBY_PKGPREFIX}-readline>=${RUBY_VERSION}:../../devel/ruby-readline
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
