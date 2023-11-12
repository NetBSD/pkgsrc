# $NetBSD: Makefile,v 1.22 2023/11/12 13:21:12 wiz Exp $

DISTNAME=	rubysdl-2.2.0
PKGREVISION=	3
CATEGORIES=	devel audio graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kmc.gr.jp/~ohai/rubysdl.en.html
COMMENT=	Ruby extension library to use SDL library
LICENSE=	gnu-lgpl-v2.1 OR gnu-lgpl-v3

GEM_CLEANBUILD=	Makefile *.o *.time sdl_ext.${RUBY_DLEXT} mkmf.log
GEM_CLEANBUILD_EXTENSIONS= rubysdl_aliases.rb rubysdl_compatible_ver1.rb sdl.rb

.include "../../lang/ruby/gem.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
