# $NetBSD: Makefile,v 1.6 2017/12/30 04:40:20 tsutsui Exp $

DISTNAME=	twitter-text-2.1.0
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/twitter-text
COMMENT=	Library that provides text handling for Twitter
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-unf-[0-9]*:../../converters/ruby-unf
DEPENDS+=	${RUBY_PKGPREFIX}-idn-[0-9]*:../../devel/ruby-idn

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
