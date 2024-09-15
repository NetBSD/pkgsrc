# $NetBSD: Makefile,v 1.4 2024/09/15 16:48:58 taca Exp $

DISTNAME=	minitar-cli-1.0.0
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/halostatue/minitar-cli/
COMMENT=	Pure-Ruby command-line tool that uses minitar library
LICENSE=	ruby-license OR 2-clause-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-minitar>=1.0.0<1.1:../../archivers/ruby-minitar
DEPENDS+=	${RUBY_PKGPREFIX}-powerbar>=1.0:../../misc/ruby-powerbar

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	powerbar>=1.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
