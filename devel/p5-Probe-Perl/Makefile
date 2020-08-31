# $NetBSD: Makefile,v 1.17 2020/08/31 18:08:44 wiz Exp $

DISTNAME=		Probe-Perl-0.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KW/KWILLIAMS/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Probe-Perl
COMMENT=		Information about the currently running perl
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Probe/Perl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
