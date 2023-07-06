# $NetBSD: Makefile,v 1.44 2023/07/06 09:40:11 wiz Exp $

DISTNAME=		Test-Deep-1.204
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Deep
COMMENT=		Perl5 module to test deep structures
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/Deep/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
