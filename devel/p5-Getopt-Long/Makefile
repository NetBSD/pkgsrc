# $NetBSD: Makefile,v 1.40 2026/07/16 19:02:32 wiz Exp $

DISTNAME=		Getopt-Long-2.57
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Getopt-Long
COMMENT=		Extended processing of command line options
LICENSE=		${PERL5_LICENSE}

#REPLACE_PERL+=		lib/Getopt/Long.pm

PERL5_PACKLIST=		auto/Getopt/Long/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
