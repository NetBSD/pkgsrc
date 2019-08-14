# $NetBSD: Makefile,v 1.15 2019/08/14 02:32:28 wen Exp $

DISTNAME=	IO-Async-0.74
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-Async
COMMENT=	Asynchronous event-driven programming
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Future>=0.18:../../devel/p5-Future

BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Identity-[0-9]*:../../devel/p5-Test-Identity
BUILD_DEPENDS+=	p5-Test-Refcount-[0-9]*:../../devel/p5-Test-Refcount
BUILD_DEPENDS+= p5-Struct-Dumb-[0-9]*:../../devel/p5-Struct-Dumb

USE_LANGUAGES=	# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/IO/Async/.packlist

PERL5_REQD+=	5.7.3	# Storable >= 0
PERL5_REQD+=	5.7.3	# Time::HiRes >= 0
PERL5_REQD+=	5.10
PERL5_REQD+=	0	# IO::Poll >= 0
PERL5_REQD+=	2.007	# Socket >= 2.007
PERL5_REQD+=	5.4	# File::stat >= 0
PERL5_REQD+=	0	# IO::Socket::IP >= 0
PERL5_REQD+=	5.10.1	# Test::More >= 0.88
PERL5_REQD+=	5.6.1	# File::Temp >= 0

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
