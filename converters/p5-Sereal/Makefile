# $NetBSD: Makefile,v 1.13 2020/06/18 19:56:32 fcambus Exp $

DISTNAME=	Sereal-4.014
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/Y/YV/YVES/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/distribution/Sereal/lib/Sereal.pm
COMMENT=	Fast, compact, powerful binary (de-)serialization
#LICENSE=	# Copyright (C) 2012, 2013 by Steffen Mueller

DEPENDS+=	p5-Sereal-Decoder>=4.007:../../converters/p5-Sereal-Decoder
DEPENDS+=	p5-Sereal-Encoder>=4.007:../../converters/p5-Sereal-Encoder

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

PERL5_PACKLIST=	auto/Sereal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
