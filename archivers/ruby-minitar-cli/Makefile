# $NetBSD: Makefile,v 1.1 2017/03/13 16:05:58 taca Exp $

DISTNAME=	minitar-cli-0.6.1
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/halostatue/minitar-cli/
COMMENT=	Pure-Ruby command-line tool that uses minitar library
LICENSE=	ruby-license OR 2-clause-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-minitar>=0.6.0<0.7:../../archivers/ruby-minitar
DEPENDS+=	${RUBY_PKGPREFIX}-powerbar>=1.0<2:../../misc/ruby-powerbar

# XXX: graphics/ruby-color depends on minitar but using command minitar?

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
