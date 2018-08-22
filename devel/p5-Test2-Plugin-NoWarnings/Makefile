# $NetBSD: Makefile,v 1.6 2018/08/22 09:44:52 wiz Exp $

DISTNAME=		Test2-Plugin-NoWarnings-0.06
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DR/DROLSKY/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test2-Plugin-NoWarnings/
COMMENT=		Perl5 module for testing for warnings
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite
# for make test
BUILD_DEPENDS+=		p5-Sub-Info-[0-9]*:../../devel/p5-Sub-Info
BUILD_DEPENDS+=		p5-Term-Table-[0-9]*:../../devel/p5-Term-Table

PERL5_PACKLIST=		auto/Test2/Plugin/NoWarnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
