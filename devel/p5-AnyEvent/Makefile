# $NetBSD: Makefile,v 1.51 2022/06/28 11:31:51 wiz Exp $

DISTNAME=	AnyEvent-7.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AnyEvent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/AnyEvent.html
COMMENT=	Simple API for io, timer and completion callbacks
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/AnyEvent/.packlist

# 	  Task::Weaken in perl 5.14
DEPENDS+=	p5-Net-SSLeay>=1.33:../../security/p5-Net-SSLeay
DEPENDS+=	p5-JSON>=2.09:../../converters/p5-JSON
DEPENDS+=	p5-JSON-XS>=2.200:../../converters/p5-JSON-XS
DEPENDS+=	p5-EV>=4:../../devel/p5-EV
DEPENDS+=	p5-Guard>=1.020:../../devel/p5-Guard
DEPENDS+=	p5-Async-Interrupt>=1:../../devel/p5-Async-Interrupt

# setup for make test (expecting PASS with several skipping items)
#BUILD_DEPENDS+=	p5-AnyEvent-AIO-[0-9]*:../../devel/p5-AnyEvent-AIO
BUILD_DEPENDS+=		p5-IO-Async-[0-9]*:../../devel/p5-IO-Async

TEST_ENV+=	PERL_ANYEVENT_LOOP_TESTS=true
TEST_ENV+=	PERL_ANYEVENT_NET_TESTS=true

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
