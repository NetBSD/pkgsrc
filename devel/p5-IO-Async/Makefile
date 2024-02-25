# $NetBSD: Makefile,v 1.26 2024/02/25 08:41:52 wiz Exp $

DISTNAME=	IO-Async-0.803
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-Async
COMMENT=	Asynchronous event-driven programming
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Future>=0.18:../../devel/p5-Future
DEPENDS+=	p5-Struct-Dumb>=0:../../devel/p5-Struct-Dumb

TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite
TEST_DEPENDS+=	p5-Test-Metrics-Any-[0-9]*:../../devel/p5-Test-Metrics-Any
TEST_DEPENDS+=	p5-Test-Future-IO-Impl-[0-9]*:../../devel/p5-Test-Future-IO-Impl

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/IO/Async/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
