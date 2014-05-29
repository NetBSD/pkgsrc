# $NetBSD: Makefile,v 1.4 2014/05/29 23:35:23 wiz Exp $

DISTNAME=	Sereal-Encoder-2.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security perl5 converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../CPAN/authors/id/S/SM/SMUELLER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sereal-Encoder/
COMMENT=	Perl5 module for fast, compact, powerful binary serialization
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString
BUILD_DEPENDS+=	p5-Sereal-Decoder>=2.03:../../converters/p5-Sereal-Decoder

PERL5_PACKLIST=		auto/Sereal/Encoder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
