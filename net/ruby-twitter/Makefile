# $NetBSD: Makefile,v 1.10 2015/06/11 17:37:50 taca Exp $

DISTNAME=	twitter-5.14.0
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	http://sferik.github.io/twitter/
COMMENT=	Ruby interface to the Twitter API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-simple_oauth>=0.3.0:../../security/ruby-simple_oauth
DEPENDS+=	${RUBY_PKGPREFIX}-equalizer>=0.0.9:../../misc/ruby-equalizer
DEPENDS+=	${RUBY_PKGPREFIX}-memoizable>=0.4.0:../../misc/ruby-memoizable
DEPENDS+=	${RUBY_PKGPREFIX}-naught>=1.0.0:../../misc/ruby-naught
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-buftok>=0.2.0:../../textproc/ruby-buftok
DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=0.9<0.10:../../www/ruby-faraday
DEPENDS+=	${RUBY_PKGPREFIX}-http>=0.6.0:../../www/ruby-http
DEPENDS+=	${RUBY_PKGPREFIX}-http_parser.rb>=0.6.0:../../www/ruby-http_parser.rb

RUBY_JSON_REQD=	1.8
OVERRIDE_GEMSPEC+=	http>=0.6.0

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/json.mk"
.include "../../mk/bsd.pkg.mk"
