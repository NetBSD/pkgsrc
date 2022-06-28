# $NetBSD: Makefile,v 1.10 2022/06/28 11:36:01 wiz Exp $

DISTNAME=	Monitoring-Plugin-0.40
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NI/NIERLEIN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Monitoring::Plugin
COMMENT=	Family of perl modules for monitoring plugins
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor>=0.34:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Config-Tiny>=2.23:../../devel/p5-Config-Tiny
DEPENDS+=	p5-Params-Validate>=1.26:../../devel/p5-Params-Validate
DEPENDS+=	p5-Math-Calc-Units>=1.07:../../math/p5-Math-Calc-Units

PERL5_PACKLIST=	auto/Monitoring/Plugin/.packlist

PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
