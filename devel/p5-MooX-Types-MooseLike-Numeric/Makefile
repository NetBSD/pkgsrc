# $NetBSD: Makefile,v 1.14 2022/06/28 11:32:50 wiz Exp $

DISTNAME=	MooX-Types-MooseLike-Numeric-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MATEU/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooX-Types-MooseLike-Numeric
COMMENT=	Moo types for numbers
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	p5-MooX-Types-MooseLike>=0.23:../../devel/p5-Moo
# for make test
BUILD_DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
BUILD_DEPENDS+=	p5-MooX-Types-MooseLike-[0-9]*:../../devel/p5-MooX-Types-MooseLike
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_PACKLIST=	auto/MooX/Types/MooseLike/Numeric/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
