# $NetBSD: Makefile,v 1.6 2019/07/01 21:35:38 nia Exp $
#

DISTNAME=	Log-Message-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
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
