# $NetBSD: Makefile,v 1.2 2019/10/22 07:30:39 taca Exp $

DISTNAME=	minitar-cli-0.8
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/halostatue/minitar-cli/
COMMENT=	Pure-Ruby command-line tool that uses minitar library
LICENSE=	ruby-license OR 2-clause-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-minitar>=0.8.0:../../archivers/ruby-minitar
DEPENDS+=	${RUBY_PKGPREFIX}-powerbar>=1.0<2:../../misc/ruby-powerbar

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	minitar>=0.8.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
