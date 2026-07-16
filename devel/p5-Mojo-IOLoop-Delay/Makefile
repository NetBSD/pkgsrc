# $NetBSD: Makefile,v 1.5 2026/07/16 19:02:52 wiz Exp $

GITHUB_PROJECT=	Mojo-IOLoop-Delay
DISTNAME=	Mojo-IOLoop-Delay-8.76
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_GITHUB:=jberger/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jberger/Mojo-IOLoop-Delay
COMMENT=	Promises/A+ and flow-control helpers (deprecated)
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/Mojo/IOLoop/Delay/.packlist
USE_LANGUAGES=		# none

DEPENDS+=	p5-Mojolicious>=5.08:../../www/p5-Mojolicious

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
