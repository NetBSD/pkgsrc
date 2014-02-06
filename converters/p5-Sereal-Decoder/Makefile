# $NetBSD: Makefile,v 1.3 2014/02/06 12:48:52 abs Exp $

DISTNAME=	Sereal-Decoder-2.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5 converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../CPAN/authors/id/S/SM/SMUELLER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sereal-Decoder/
COMMENT=	Perl5 module for fast, compact, powerful binary deserialization
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString

PERL5_PACKLIST=		auto/Sereal/Decoder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
