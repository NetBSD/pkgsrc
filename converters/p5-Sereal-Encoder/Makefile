# $NetBSD: Makefile,v 1.18 2019/08/11 13:18:14 wiz Exp $

DISTNAME=	Sereal-Encoder-4.007
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security perl5 converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../CPAN/authors/id/Y/YV/YVES/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sereal-Encoder
COMMENT=	Perl5 module for fast, compact, powerful binary serialization
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
BUILD_DEPENDS+=	p5-Sereal-Decoder>=4.002:../../converters/p5-Sereal-Decoder

PERL5_PACKLIST=		auto/Sereal/Encoder/.packlist

# dependency problem in 4.002 with zstd/
MAKE_JOBS_SAFE=		no

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
