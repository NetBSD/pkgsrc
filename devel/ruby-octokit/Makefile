# $NetBSD: Makefile,v 1.19 2023/03/15 14:27:56 taca Exp $

DISTNAME=	octokit-6.1.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/octokit/octokit.rb
COMMENT=	Ruby toolkit for working with the GitHub API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sawyer>=0.9.2nb1:../../www/ruby-sawyer
DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=1<3:../../www/ruby-faraday

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
