# $NetBSD: Makefile,v 1.24 2023/11/12 13:21:27 wiz Exp $

DISTNAME=	Font-FreeType-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	perl5 fonts graphics
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Font-FreeType
COMMENT=	Read font files and render glyphs from Perl using FreeType2
LICENSE=	${PERL5_LICENSE}

USE_TOOLS+=	pkg-config

DEPENDS+=	p5-Devel-CheckLib-[0-9]*:../../devel/p5-Devel-CheckLib
DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which

# for make test
TOOL_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

PERL5_PACKLIST=		auto/Font/FreeType/.packlist

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
