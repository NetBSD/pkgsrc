# $NetBSD: Makefile,v 1.3 2024/07/14 08:06:25 taca Exp $

DISTNAME=	minitar-cli-0.9
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/halostatue/minitar-cli/
COMMENT=	Pure-Ruby command-line tool that uses minitar library
LICENSE=	ruby-license OR 2-clause-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-minitar>=0.9.0:../../archivers/ruby-minitar
DEPENDS+=	${RUBY_PKGPREFIX}-powerbar>=1.0<2:../../misc/ruby-powerbar

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	minitar>=0.8.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
