# $NetBSD: Makefile,v 1.17 2022/08/24 15:56:23 taca Exp $

DISTNAME=	octokit-4.25.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/octokit/octokit.rb
COMMENT=	Ruby toolkit for working with the GitHub API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sawyer>=0.9:../../www/ruby-sawyer
DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=1:../../www/ruby-faraday

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
