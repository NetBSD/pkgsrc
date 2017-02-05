# $NetBSD: Makefile,v 1.13 2017/02/05 01:19:51 tsutsui Exp $

DISTNAME=	twitter-6.1.0
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	http://sferik.github.io/twitter/
COMMENT=	Ruby interface to the Twitter API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-simple_oauth>=0.3.1:../../security/ruby-simple_oauth
DEPENDS+=	${RUBY_PKGPREFIX}-equalizer>=0.0.11:../../misc/ruby-equalizer
DEPENDS+=	${RUBY_PKGPREFIX}-memoizable>=0.4.2:../../misc/ruby-memoizable
DEPENDS+=	${RUBY_PKGPREFIX}-naught>=1.1:../../misc/ruby-naught
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.5:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-buftok>=0.2.0:../../textproc/ruby-buftok
DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=0.11:../../www/ruby-faraday
DEPENDS+=	${RUBY_PKGPREFIX}-http>=2.1:../../www/ruby-http
DEPENDS+=	${RUBY_PKGPREFIX}-http_parser.rb>=0.6.0:../../www/ruby-http_parser.rb

OVERRIDE_GEMSPEC+=	equalizer>=0.0.11

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
