# $NetBSD: Makefile,v 1.14 2019/06/30 20:15:22 nia Exp $

DISTNAME=	MooX-Types-MooseLike-0.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MATEU/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooX-Types-MooseLike
COMMENT=	Some Moosish types and a type builder
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Moo>=0.091010:../../devel/p5-Moo
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
DEPENDS+=	p5-Module-Runtime>=0.012:../../devel/p5-Module-Runtime

PERL5_PACKLIST=	auto/MooX/Types/MooseLike/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
