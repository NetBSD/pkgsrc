# $NetBSD: Makefile,v 1.11 2022/06/28 11:32:31 wiz Exp $

DISTNAME=	GitLab-API-v3-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BL/BLUEFEET/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/GitLab-API-v3
COMMENT=	Complete GitLab API v3 client
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Const-Fast-[0-9]*:../../devel/p5-Const-Fast
DEPENDS+=	p5-Log-Any-Adapter-Screen-[0-9]*:../../devel/p5-Log-Any-Adapter-Screen
DEPENDS+=	p5-Log-Any-Adapter-TAP-[0-9]*:../../devel/p5-Log-Any-Adapter-TAP
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-Role-REST-Client>=0.18:../../www/p5-Role-REST-Client
DEPENDS+=	p5-Moo>=1.006:../../devel/p5-Moo

PERL5_MODULE_TYPE=	Module::Build::Tiny
REPLACE_PERL+=		script/gitlab-api-v3

PERL5_PACKLIST=	auto/GitLab/API/v3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
