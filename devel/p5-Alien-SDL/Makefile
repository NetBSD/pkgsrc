# $NetBSD: Makefile,v 1.5 2018/11/12 03:51:54 ryoon Exp $

DISTNAME=	Alien-SDL-1.446
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Alien/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~froggs/Alien-SDL/lib/Alien/SDL.pm
COMMENT=	Alien::SDL - building, finding and using SDL binaries
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-Archive-Extract-[0-9]*:../../archivers/p5-Archive-Extract

DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=	p5-Module-Build>=0.36:../../devel/p5-Module-Build
DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which
DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny

DEPENDS+=	p5-Text-Patch>=1.4:../../textproc/p5-Text-Patch
DEPENDS+=	p5-Digest-SHA-[0-9]*:../../security/p5-Digest-SHA
DEPENDS+=	p5-Tie-Simple-[0-9]*:../../devel/p5-Tie-Simple

# To set this configure log "checking SDL_INST_DIR env var... yes, /usr/pkg"
MAKE_ENV+=	SDL_INST_DIR=${PREFIX}
USE_LANGUAGES=		c

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Adjust path (see console output at configure stage)
SUBST_FILES.path=	inc/My/Utility.pm
SUBST_STAGE.path=	pre-configure
SUBST_SED.path=		-e 's|/usr/local/|${PREFIX}/|g'
SUBST_SED.path+=	-e 's|/usr/include/|${PREFIX}/include/|g'
SUBST_SED.path+=	-e 's|/usr/X11R7/|${X11BASE}/|g'

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Alien/SDL/.packlist
PERL5_PACKLIST_DIR=	${PERL5_INSTALLVENDORARCH:S/vendor_perl/site_perl/}

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../devel/SDL_Pango/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
