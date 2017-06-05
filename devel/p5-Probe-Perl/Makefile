# $NetBSD: Makefile,v 1.13 2017/06/05 14:23:30 ryoon Exp $

DISTNAME=		Probe-Perl-0.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KW/KWILLIAMS/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Probe-Perl/
COMMENT=		Information about the currently running perl
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Probe/Perl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
