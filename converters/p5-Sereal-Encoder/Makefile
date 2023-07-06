# $NetBSD: Makefile,v 1.29 2023/07/06 09:38:16 wiz Exp $

DISTNAME=	Sereal-Encoder-5.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../CPAN/authors/id/Y/YV/YVES/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sereal-Encoder
COMMENT=	Perl5 module for fast, compact, powerful binary serialization
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TOOL_DEPENDS+=	p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString
TOOL_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
TOOL_DEPENDS+=	p5-Sereal-Decoder>=4.002:../../converters/p5-Sereal-Decoder

PERL5_PACKLIST=		auto/Sereal/Encoder/.packlist

# dependency problem in 4.002 with zstd/
MAKE_JOBS_SAFE=		no

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
