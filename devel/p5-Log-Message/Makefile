# $NetBSD: Makefile,v 1.10 2022/06/28 11:32:42 wiz Exp $
#

DISTNAME=	Log-Message-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
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
