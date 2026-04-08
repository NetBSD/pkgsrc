# $NetBSD: Makefile,v 1.3 2026/04/08 14:29:33 taca Exp $

DISTNAME=	octokit-4.25.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/octokit/&4/}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/octokit/octokit.rb
COMMENT=	Ruby toolkit for working with the GitHub API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sawyer>=0.9.2nb1:../../www/ruby-sawyer
DEPENDS+=	${RUBY_PKGPREFIX}-faraday1>=1:../../www/ruby-faraday1

USE_LANGUAGES=	# none

RUBY_VERSIONS_ACCEPTED=	33 34

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
