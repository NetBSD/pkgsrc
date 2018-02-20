# $NetBSD: Makefile,v 1.1 2018/02/20 14:04:23 fhajny Exp $
#

DISTNAME=	Math-Int64-0.54
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

HOMEPAGE=	http://search.cpan.org/dist/Math-Int64/
COMMENT=	Manipulate 64 bits integers in Perl
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Math/Int64/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
