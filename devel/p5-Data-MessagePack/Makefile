# $NetBSD: Makefile,v 1.16 2019/06/30 20:14:48 nia Exp $
#

DISTNAME=	Data-MessagePack-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-MessagePack
COMMENT=	MessagePack serialising/deserialising
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Requires>=0:../../devel/p5-Test-Requires

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Data/MessagePack/.packlist
USE_LANGUAGES=	c99

MAKE_JOBS_SAFE=	no

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
