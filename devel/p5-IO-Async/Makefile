# $NetBSD: Makefile,v 1.23 2022/06/28 11:32:34 wiz Exp $

DISTNAME=	IO-Async-0.79
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-Async
COMMENT=	Asynchronous event-driven programming
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Future>=0.18:../../devel/p5-Future

TEST_DEPENDS+=	p5-Test-Metrics-Any-[0-9]*:../../devel/p5-Test-Metrics-Any
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-Identity-[0-9]*:../../devel/p5-Test-Identity
TEST_DEPENDS+=	p5-Test-Refcount-[0-9]*:../../devel/p5-Test-Refcount
TEST_DEPENDS+=	p5-Struct-Dumb-[0-9]*:../../devel/p5-Struct-Dumb

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/IO/Async/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
