# $NetBSD: Makefile,v 1.21 2021/05/24 19:51:50 wiz Exp $

DISTNAME=		Test-Trap-v0.3.4
PKGNAME=		p5-${DISTNAME:S/v0/0/}
PKGREVISION=		4
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
