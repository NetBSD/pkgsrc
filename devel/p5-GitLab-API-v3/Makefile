# $NetBSD: Makefile,v 1.4 2018/08/22 09:44:05 wiz Exp $

DISTNAME=	GitLab-API-v3-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BL/BLUEFEET/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/GitLab-API-v3
COMMENT=	Complete GitLab API v3 client
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Const-Fast-[0-9]*:../../devel/p5-Const-Fast
DEPENDS+=	p5-Log-Any-Adapter-Screen-[0-9]*:../../devel/p5-Log-Any-Adapter-Screen
DEPENDS+=	p5-Log-Any-Adapter-TAP-[0-9]*:../../devel/p5-Log-Any-Adapter-TAP
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-Role-REST-Client>=0.18:../../www/p5-Role-REST-Client

REPLACE_PERL+=	bin/gitlab-api-v3

PERL5_PACKLIST=	auto/GitLab/API/v3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
