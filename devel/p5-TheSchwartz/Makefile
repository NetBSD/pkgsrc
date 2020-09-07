# $NetBSD: Makefile,v 1.8 2020/09/07 10:18:53 wiz Exp $

DISTNAME=		TheSchwartz-1.15
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AK/AKIYM/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		https://metacpan.org/release/TheSchwartz
COMMENT=		Reliable job queue system
LICENSE=		artistic-2.0

DEPENDS+=		p5-Data-ObjectDriver>=0.04:../../devel/p5-Data-ObjectDriver
#DEPENDS+=		p5-Storable-[0-9]*:../../devel/p5-Storable

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/TheSchwartz/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
