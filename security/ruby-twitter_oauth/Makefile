# $NetBSD: Makefile,v 1.8 2015/03/15 16:56:49 hiramatsu Exp $

DISTNAME=	twitter_oauth-0.4.94
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/moomerman/twitter_oauth
COMMENT=	Ruby client for the Twitter API using OAuth
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.4.7:../../security/ruby-oauth

RUBY_JSON_REQD=	1.8.0

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/json.mk"
.include "../../mk/bsd.pkg.mk"
