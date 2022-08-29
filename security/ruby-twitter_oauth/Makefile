# $NetBSD: Makefile,v 1.11 2022/08/29 14:20:56 wiz Exp $

DISTNAME=	twitter_oauth-0.4.94
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/moomerman/twitter_oauth
COMMENT=	Ruby client for the Twitter API using OAuth
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.4.7:../../security/ruby-oauth

RUBY_VERSIONS_INCOMPATIBLE=	26 # ruby-oauth

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
