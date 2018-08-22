# $NetBSD: Makefile,v 1.11 2018/08/22 09:44:19 wiz Exp $

GITHUB_PROJECT=	Mojo-IOLoop-ForkCall
DISTNAME=	Mojo-IOLoop-ForkCall-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jberger/}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/jberger/Mojo-IOLoop-ForkCall/
COMMENT=	Execute a code block asynchronously by forking
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Mojo/IOLoop/ForkCall/.packlist
USE_LANGUAGES=		# none

DEPENDS+=	p5-IO-Pipely-[0-9]*:../../devel/p5-IO-Pipely
DEPENDS+=	p5-Mojolicious>=5.08:../../www/p5-Mojolicious

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
