# $NetBSD: Makefile,v 1.1 2016/11/07 10:43:08 wiz Exp $

DISTNAME=		Test2-Plugin-NoWarnings-0.04
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DR/DROLSKY/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test2-Plugin-NoWarnings/
COMMENT=		Perl5 module for testing for warnings
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite

PERL5_PACKLIST=		auto/Test2/Plugin/NoWarnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
