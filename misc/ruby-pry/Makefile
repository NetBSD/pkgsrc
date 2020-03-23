# $NetBSD: Makefile,v 1.11 2020/03/23 17:09:20 taca Exp $

DISTNAME=	pry-0.13.0
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pry/pry
COMMENT=	IRB alternative and runtime developer console
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-readline>=${RUBY_VERSION}:../../devel/ruby-readline
DEPENDS+=	${RUBY_PKGPREFIX}-method_source>=1.0<2:../../misc/ruby-method_source
DEPENDS+=	${RUBY_PKGPREFIX}-coderay>=1.1.0<2.0:../../textproc/ruby-coderay

RUBYGEM_OPTIONS+=	--format-executable

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
