# $NetBSD: Makefile,v 1.4 2016/06/08 19:23:47 wiz Exp $

DISTNAME=	multidimensional-0.011
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IL/ILMARI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/multidimensional/
COMMENT=	Perl 5 module to disable multidmensional array emulation
LICENSE=	${PERL5_LICENSE}

BUILDLINK_API_DEPENDS.p5-B-Hooks-OP-Check+=     p5-B-Hooks-OP-Check>=0.19
DEPENDS+=	p5-ExtUtils-Depends-[0-9]*:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-Lexical-SealRequireHints>=0.005:../../devel/p5-Lexical-SealRequireHints
# CPAN::Meta 2.112580 is in core since 5.15.1 - so current lang/perl5 satisfies

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/multidimensional/.packlist

.include "../../devel/p5-B-Hooks-OP-Check/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
