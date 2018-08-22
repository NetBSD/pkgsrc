# $NetBSD: Makefile,v 1.5 2018/08/22 09:44:14 wiz Exp $
#

DISTNAME=	Log-Message-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~bingos/Log-Message/
COMMENT=	Log::Message - A generic message storing mechanism
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Log/Message/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
