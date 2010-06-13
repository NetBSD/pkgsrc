# $NetBSD: Makefile,v 1.6 2010/06/13 22:44:10 wiz Exp $

DISTNAME=	rubysdl-2.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rubysdl/SDL/}
PKGREVISION=	3
CATEGORIES=	devel audio graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kmc.gr.jp/~ohai/rubysdl.en.html
COMMENT=	Ruby extension library to use SDL library

GEM_BUILD=	gemspec
GEM_CLEANBUILD=	Makefile *.o sdl.${RUBY_DLEXT} mkmf.log

.include "../../misc/rubygems/rubygem.mk"

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
