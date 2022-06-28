# $NetBSD: Makefile,v 1.13 2022/06/28 11:33:32 wiz Exp $

DISTNAME=		Test2-Plugin-NoWarnings-0.09
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DR/DROLSKY/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test2-Plugin-NoWarnings
COMMENT=		Perl5 module for testing for warnings
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite
TEST_DEPENDS+=		p5-Sub-Info-[0-9]*:../../devel/p5-Sub-Info
TEST_DEPENDS+=		p5-Term-Table-[0-9]*:../../devel/p5-Term-Table
TEST_DEPENDS+=		p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3

PERL5_PACKLIST=		auto/Test2/Plugin/NoWarnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
