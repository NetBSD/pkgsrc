# $NetBSD: Makefile,v 1.34 2019/10/19 12:52:40 mef Exp $

DISTNAME=		Getopt-Long-2.51
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Getopt-Long
COMMENT=		Extended processing of command line options
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-Perl4-CoreLibs-[0-9]*:../../devel/p5-Perl4-CoreLibs

REPLACE_PERL+=	lib/Getopt/Long.pm

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Getopt/Long/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
