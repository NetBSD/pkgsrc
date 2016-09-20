# $NetBSD: Makefile,v 1.6 2016/09/20 11:40:27 mef Exp $
#

DISTNAME=	Font-FreeType-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 fonts graphics
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Font-FreeType/
COMMENT=	Read font files and render glyphs from Perl using FreeType2
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Font/FreeType/.packlist

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
# to find freetype-config
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
