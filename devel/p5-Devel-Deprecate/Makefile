# $NetBSD: Makefile,v 1.1 2026/08/03 13:24:41 wiz Exp $

DISTNAME=	Devel-Deprecate-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/O/OV/OVID/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Devel::Deprecate
COMMENT=	Perl module to create deprecation schedules in your code
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0.3:../../time/p5-DateTime

PERL5_PACKLIST=		auto/Devel/Deprecate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
