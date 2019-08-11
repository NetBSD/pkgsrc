# $NetBSD: Makefile,v 1.11 2019/08/11 13:20:47 wiz Exp $

DISTNAME=	multidimensional-0.014
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IL/ILMARI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/multidimensional
COMMENT=	Perl 5 module to disable multidmensional array emulation
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-ExtUtils-Depends-[0-9]*:../../devel/p5-ExtUtils-Depends

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/multidimensional/.packlist

BUILDLINK_API_DEPENDS.p5-B-Hooks-OP-Check+=     p5-B-Hooks-OP-Check>=0.22
.include "../../devel/p5-B-Hooks-OP-Check/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
