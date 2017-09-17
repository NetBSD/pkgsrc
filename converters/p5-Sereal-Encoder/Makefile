# $NetBSD: Makefile,v 1.11 2017/09/17 08:25:14 wiz Exp $

DISTNAME=	Sereal-Encoder-3.015
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5 converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../CPAN/authors/id/Y/YV/YVES/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sereal-Encoder/
COMMENT=	Perl5 module for fast, compact, powerful binary serialization
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
BUILD_DEPENDS+=	p5-Sereal-Decoder>=2.03:../../converters/p5-Sereal-Decoder

PERL5_PACKLIST=		auto/Sereal/Encoder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
