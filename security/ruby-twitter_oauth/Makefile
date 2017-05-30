# $NetBSD: Makefile,v 1.9 2017/05/30 15:13:03 taca Exp $

DISTNAME=	twitter_oauth-0.4.94
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/moomerman/twitter_oauth
COMMENT=	Ruby client for the Twitter API using OAuth
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.4.7:../../security/ruby-oauth

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
