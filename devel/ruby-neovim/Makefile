# $NetBSD: Makefile,v 1.2 2023/08/13 14:18:52 taca Exp $

DISTNAME=	neovim-0.9.1
CATEGORIES=	devel editors

HOMEPAGE=	https://github.com/neovim/neovim-ruby
COMMENT=	Ruby client to Neovim
LICENSE=	mit
MAINTAINER=	pkgsrc-users@NetBSD.org

DEPENDS+=	${RUBY_PKGPREFIX}-msgpack>=1.0.0:../../devel/ruby-msgpack
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json-[0-9]*:../../textproc/ruby-multi_json

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
