# $NetBSD: Makefile,v 1.5 2017/07/08 03:14:20 tsutsui Exp $

DISTNAME=	twitter-text-1.14.7
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/twitter-text
COMMENT=	Library that provides text handling for Twitter
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-unf-[0-9]*:../../converters/ruby-unf

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
