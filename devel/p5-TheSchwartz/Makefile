# $NetBSD: Makefile,v 1.13 2023/07/06 09:40:21 wiz Exp $

DISTNAME=		TheSchwartz-1.17
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AK/AKIYM/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		https://metacpan.org/release/TheSchwartz
COMMENT=		Reliable job queue system
LICENSE=		artistic-2.0

DEPENDS+=		p5-Data-ObjectDriver>=0.04:../../devel/p5-Data-ObjectDriver

PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/TheSchwartz/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
