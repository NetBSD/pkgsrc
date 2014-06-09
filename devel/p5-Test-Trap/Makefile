# $NetBSD: Makefile,v 1.7 2014/06/09 19:07:04 schmonz Exp $

DISTNAME=		Test-Trap-v0.2.4
PKGNAME=		p5-${DISTNAME:S/v0/0/}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Trap/
COMMENT=		Perl extension to trap exit codes, exceptions, output
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=		p5-Test-Tester>=0.107:../../devel/p5-Test-Tester

PERL5_PACKLIST=		auto/Test/Trap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
