# $NetBSD: Makefile,v 1.22 2022/06/28 11:33:31 wiz Exp $

DISTNAME=		Test-Trap-v0.3.4
PKGNAME=		p5-${DISTNAME:S/v0/0/}
PKGREVISION=		5
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Trap
COMMENT=		Perl extension to trap exit codes, exceptions, output
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump

PERL5_PACKLIST=		auto/Test/Trap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
