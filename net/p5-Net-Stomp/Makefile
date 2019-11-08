# $NetBSD: Makefile,v 1.5 2019/11/08 15:04:31 mef Exp $
#

DISTNAME=	Net-Stomp-0.60
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

HOMEPAGE=	https://metacpan.org/release/Net-Stomp
COMMENT=	Streaming Text Orientated Messaging Protocol Client
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-NiceDump-[0-9]*:../../devel/p5-Test-NiceDump

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Net/Stomp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
