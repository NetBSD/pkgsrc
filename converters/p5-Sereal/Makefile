# $NetBSD: Makefile,v 1.1 2017/05/28 13:23:34 mef Exp $

DISTNAME=	Sereal-0.330
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/Y/YV/YVES/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~yves/Sereal/lib/Sereal.pm
COMMENT=	Fast, compact, powerful binary (de-)serialization
#LICENSE=	# Copyright (C) 2012, 2013 by Steffen Mueller

DEPENDS+=	p5-Sereal-Decoder-[0-9]*:../../converters/p5-Sereal-Decoder
DEPENDS+=	p5-Sereal-Encoder-[0-9]*:../../converters/p5-Sereal-Encoder

PERL5_PACKLIST=	auto/Sereal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
