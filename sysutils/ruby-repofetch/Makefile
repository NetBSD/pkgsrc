# $NetBSD: Makefile,v 1.2 2023/01/15 15:48:01 taca Exp $

DISTNAME=	repofetch-0.4.4
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spenserblack/repofetch
COMMENT=	Plugin-based stat fetcher
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONVIEW_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-dotenv>=2.8<3:../../devel/ruby-dotenv
DEPENDS+=	${RUBY_PKGPREFIX}-faraday-retry>=2.0<3:../../www/ruby-faraday-retry
DEPENDS+=	${RUBY_PKGPREFIX}-git>=1.12<2:../../devel/ruby-git
DEPENDS+=	${RUBY_PKGPREFIX}-octokit>=6.0<7:../../devel/ruby-octokit
#DEPENDS+=	${RUBY_PKGPREFIX}-sawyer>=0.9<1:../../www/ruby-sawyer

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	70
RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
