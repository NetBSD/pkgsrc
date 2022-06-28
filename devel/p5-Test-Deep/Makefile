# $NetBSD: Makefile,v 1.42 2022/06/28 11:33:22 wiz Exp $

DISTNAME=		Test-Deep-1.130
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Deep
COMMENT=		Perl5 module to test deep structures
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/Deep/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
