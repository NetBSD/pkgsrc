# $NetBSD: Makefile,v 1.5 2013/05/31 12:40:13 wiz Exp $
#

DISTNAME=	Data-MessagePack-0.39
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-MessagePack/
COMMENT=	MessagePack serialising/deserialising
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Requires>=0:../../devel/p5-Test-Requires

PERL5_PACKLIST=	auto/Data/MessagePack/.packlist
USE_LANGUAGES=	c99

MAKE_JOBS_SAFE=	no

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
