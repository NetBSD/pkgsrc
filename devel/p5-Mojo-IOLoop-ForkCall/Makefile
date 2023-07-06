# $NetBSD: Makefile,v 1.21 2023/07/06 09:39:35 wiz Exp $

GITHUB_PROJECT=	Mojo-IOLoop-ForkCall
PKGREVISION=	2
DISTNAME=	Mojo-IOLoop-ForkCall-0.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_GITHUB:=jberger/}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/jberger/Mojo-IOLoop-ForkCall/
COMMENT=	Execute a code block asynchronously by forking
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Mojo/IOLoop/ForkCall/.packlist
USE_LANGUAGES=		# none

DEPENDS+=	p5-IO-Pipely-[0-9]*:../../devel/p5-IO-Pipely
DEPENDS+=	p5-Mojo-IOLoop-Delay>=8.76:../../devel/p5-Mojo-IOLoop-Delay
DEPENDS+=	p5-Mojolicious>=5.08:../../www/p5-Mojolicious

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
