# $NetBSD: Makefile,v 1.3 2024/06/10 15:13:19 taca Exp $

DISTNAME=	neovim-0.10.0
CATEGORIES=	devel editors

HOMEPAGE=	https://github.com/neovim/neovim-ruby
COMMENT=	Ruby client to Neovim
LICENSE=	mit
MAINTAINER=	pkgsrc-users@NetBSD.org

DEPENDS+=	${RUBY_PKGPREFIX}-msgpack>=1.0.0:../../devel/ruby-msgpack
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json-[0-9]*:../../textproc/ruby-multi_json

RUBYGEM_OPTIONS+=	--format-executable

REPLACE_SH+=	script/host_wrapper.sh

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
