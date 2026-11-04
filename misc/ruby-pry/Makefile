# $NetBSD: Makefile,v 1.20 2026/11/04 15:28:54 taca Exp $

DISTNAME=	pry-0.16.1
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pry/pry
COMMENT=	IRB alternative and runtime developer console
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-method_source>=1.0<2:../../misc/ruby-method_source
DEPENDS+=	${RUBY_PKGPREFIX}-coderay>=1.1.0<2.0:../../textproc/ruby-coderay

RUBYGEM_OPTIONS+=	--format-executable

USE_LANGUAGES=	# none

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} < 34
DEPENDS+=	${RUBY_PKGPREFIX}-reline>=0.6.0:../../devel/ruby-reline
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
