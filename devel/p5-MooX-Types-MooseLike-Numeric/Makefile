# $NetBSD: Makefile,v 1.17 2024/11/16 12:04:41 wiz Exp $

DISTNAME=	MooX-Types-MooseLike-Numeric-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MATEU/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooX-Types-MooseLike-Numeric
COMMENT=	Moo types for numbers
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	p5-MooX-Types-MooseLike>=0.23:../../devel/p5-Moo
# for make test
TOOL_DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
TOOL_DEPENDS+=	p5-MooX-Types-MooseLike-[0-9]*:../../devel/p5-MooX-Types-MooseLike
TOOL_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_PACKLIST=	auto/MooX/Types/MooseLike/Numeric/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
