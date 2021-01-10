# $NetBSD: Makefile,v 1.14 2021/01/10 15:27:12 taca Exp $

DISTNAME=	octokit-4.20.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/octokit/octokit.rb
COMMENT=	Ruby toolkit for working with the GitHub API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sawyer>=0.8.1:../../www/ruby-sawyer
DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=0.9:../../www/ruby-faraday

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
