# $NetBSD: Makefile,v 1.1 2013/02/25 03:12:59 wen Exp $

DISTNAME=	MooX-Types-MooseLike-0.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MATEU/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Moo/
COMMENT=	Some Moosish types and a type builder
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moo>=0.09010:../../devel/p5-Moo
DEPENDS+=	p5-Module-Runtime>=0.012:../../devel/p5-Module-Runtime

PERL5_PACKLIST=	auto/MooX-Types-MooseLike/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
