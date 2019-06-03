# $NetBSD: Makefile,v 1.1 2019/06/03 11:20:59 markd Exp $

DISTNAME=	GitLab-API-v4-0.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BL/BLUEFEET/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/GitLab-API-v4
COMMENT=	Complete GitLab API v4 client
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Const-Fast-[0-9]*:../../devel/p5-Const-Fast
DEPENDS+=	p5-IO-Prompter-[0-9]*:../../devel/p5-IO-Prompter
DEPENDS+=	p5-Log-Any-Adapter-Screen>=0.13:../../devel/p5-Log-Any-Adapter-Screen
DEPENDS+=	p5-Log-Any-Adapter-TAP-[0-9]*:../../devel/p5-Log-Any-Adapter-TAP
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-HTTP-Tiny-Multipart>=0.08:../../www/p5-HTTP-Tiny-Multipart
DEPENDS+=	p5-Role-REST-Client>=0.22:../../www/p5-Role-REST-Client

REPLACE_PERL+=	bin/gitlab-api-v4

PERL5_PACKLIST=	auto/GitLab/API/v4/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
