# $NetBSD: Makefile,v 1.23 2023/07/06 09:41:43 wiz Exp $

DISTNAME=	Pod-Elemental-PerlMunger-0.200007
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Pod-Elemental-PerlMunger
COMMENT=	Perl5 module that takes a string of Perl and rewrites its Pod
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-PPI-[0-9]*:../../devel/p5-PPI
DEPENDS+=	p5-Pod-Elemental>=0.103000:../../textproc/p5-Pod-Elemental
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

PERL5_PACKLIST=		auto/Pod/Elemental/PerlMunger/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
