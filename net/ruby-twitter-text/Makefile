# $NetBSD: Makefile,v 1.4 2017/02/05 10:45:59 tsutsui Exp $

DISTNAME=	twitter-text-1.14.5
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/twitter-text
COMMENT=	Library that provides text handling for Twitter
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-unf-[0-9]*:../../converters/ruby-unf

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
