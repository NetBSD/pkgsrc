# $NetBSD: Makefile,v 1.1 2013/07/03 06:41:50 sno Exp $

DISTNAME=	Sereal-Decoder-0.36
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5 converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../CPAN/authors/id/Y/YV/YVES/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sereal-Decoder/
COMMENT=	Perl5 module for fast, compact, powerful binary deserialization
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString

PERL5_PACKLIST=		auto/Sereal/Decoder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
