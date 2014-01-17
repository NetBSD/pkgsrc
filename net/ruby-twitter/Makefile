# $NetBSD: Makefile,v 1.3 2014/01/17 18:17:37 tsutsui Exp $

DISTNAME=	twitter-5.5.1
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	http://sferik.github.io/twitter/
COMMENT=	Ruby interface to the Twitter API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-simple_oauth>=0.2.0:../../security/ruby-simple_oauth
DEPENDS+=	${RUBY_PKGPREFIX}-descendants_tracker>=0.0.3:../../misc/ruby-descendants_tracker
DEPENDS+=	${RUBY_PKGPREFIX}-equalizer>=0.0.9:../../misc/ruby-equalizer
DEPENDS+=	${RUBY_PKGPREFIX}-memoizable>=0.4.0:../../misc/ruby-memoizable
DEPENDS+=	${RUBY_PKGPREFIX}-addressable-[0-9]*:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-buftok>=0.2.0:../../textproc/ruby-buftok
DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=0.8<0.10:../../www/ruby-faraday
DEPENDS+=	${RUBY_PKGPREFIX}-http>=0.5.0:../../www/ruby-http
DEPENDS+=	${RUBY_PKGPREFIX}-http_parser.rb>=0.6.0:../../www/ruby-http_parser.rb

RUBY_JSON_REQD=	1.8

RUBY_VERSION_SUPPORTED=	200 193

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/json.mk"
.include "../../mk/bsd.pkg.mk"
