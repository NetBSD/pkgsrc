# $NetBSD: Makefile,v 1.7 2019/08/11 13:19:45 wiz Exp $
#

DISTNAME=	Log-Message-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Log-Message
COMMENT=	Log::Message - A generic message storing mechanism
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Log/Message/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
