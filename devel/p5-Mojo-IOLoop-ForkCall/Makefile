# $NetBSD: Makefile,v 1.7 2017/06/05 14:23:17 ryoon Exp $

VERSION=	0.17
DISTNAME=	${VERSION}
PKGNAME=	p5-Mojo-IOLoop-ForkCall-${VERSION}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jberger/Mojo-IOLoop-ForkCall/archive/

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/jberger/Mojo-IOLoop-ForkCall/
COMMENT=	Execute a code block asynchronously by forking
LICENSE=	${PERL5_LICENSE}

WRKSRC=			${WRKDIR}/Mojo-IOLoop-ForkCall-${VERSION}
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Mojo/IOLoop/ForkCall/.packlist
USE_LANGUAGES=		# none

DEPENDS+=	p5-IO-Pipely-[0-9]*:../../devel/p5-IO-Pipely
DEPENDS+=	p5-Mojolicious>=5.08:../../www/p5-Mojolicious

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
