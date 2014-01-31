# $NetBSD: Makefile,v 1.2 2014/01/31 10:44:47 obache Exp $
#

DISTNAME=	Font-FreeType-0.03
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
.include "../../mk/bsd.pkg.mk"
