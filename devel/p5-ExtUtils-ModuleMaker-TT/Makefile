# $NetBSD: Makefile,v 1.15 2019/08/11 13:19:24 wiz Exp $

DISTNAME=	ExtUtils-ModuleMaker-TT-0.94
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/ExtUtils-ModuleMaker-TT
COMMENT=	Makes skeleton modules with Template Toolkit templates
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Config-Find>=0.22:../../devel/p5-Config-Find
DEPENDS+=	p5-Config-General>=2.29:../../devel/p5-Config-General
DEPENDS+=	p5-ExtUtils-ModuleMaker>=0.46:../../devel/p5-ExtUtils-ModuleMaker
DEPENDS+=	p5-File-pushd>=0.32:../../devel/p5-File-pushd
DEPENDS+=	p5-Path-Class>=0.15:../../devel/p5-Path-Class
DEPENDS+=	p5-Probe-Perl>=0.01:../../devel/p5-Probe-Perl
DEPENDS+=	p5-Template-Toolkit>=2.14:../../www/p5-Template-Toolkit

PERL5_PACKLIST=		auto/ExtUtils/ModuleMaker/TT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
