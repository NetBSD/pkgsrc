# $NetBSD: Makefile,v 1.1 2023/01/01 22:11:42 nikita Exp $

DISTNAME=	neovim-0.9.0
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
