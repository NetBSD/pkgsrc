# $NetBSD: Makefile,v 1.22 2023/07/06 09:38:16 wiz Exp $

DISTNAME=	Sereal-5.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/Y/YV/YVES/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/distribution/Sereal/lib/Sereal.pm
COMMENT=	Fast, compact, powerful binary (de-)serialization
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sereal-Decoder>=4.007:../../converters/p5-Sereal-Decoder
DEPENDS+=	p5-Sereal-Encoder>=4.007:../../converters/p5-Sereal-Encoder

# TEST_DEPENDS
TOOL_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TOOL_DEPENDS+=	p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString
TOOL_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

PERL5_PACKLIST=	auto/Sereal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
