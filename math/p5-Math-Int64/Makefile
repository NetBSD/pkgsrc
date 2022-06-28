# $NetBSD: Makefile,v 1.7 2022/06/28 11:34:40 wiz Exp $
#

DISTNAME=	Math-Int64-0.54
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

HOMEPAGE=	https://metacpan.org/release/Math-Int64
COMMENT=	Manipulate 64 bits integers in Perl
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Math/Int64/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
