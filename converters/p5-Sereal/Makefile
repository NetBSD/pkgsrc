# $NetBSD: Makefile,v 1.10 2019/08/11 13:18:14 wiz Exp $

DISTNAME=	Sereal-4.007
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
