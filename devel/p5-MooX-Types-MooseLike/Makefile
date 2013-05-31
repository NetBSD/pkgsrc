# $NetBSD: Makefile,v 1.2 2013/05/31 12:40:31 wiz Exp $

DISTNAME=	MooX-Types-MooseLike-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
