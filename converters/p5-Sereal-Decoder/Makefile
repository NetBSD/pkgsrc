# $NetBSD: Makefile,v 1.28 2023/06/06 12:40:25 riastradh Exp $

DISTNAME=	Sereal-Decoder-5.003
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../CPAN/authors/id/Y/YV/YVES/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sereal-Decoder
COMMENT=	Perl5 module for fast, compact, powerful binary deserialization
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString
TOOL_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
TOOL_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TOOL_DEPENDS+=	p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences

PERL5_PACKLIST=		auto/Sereal/Decoder/.packlist

# problem with zstd/ in 4.002
MAKE_JOBS_SAFE=		no

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
