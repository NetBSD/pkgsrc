# $NetBSD: Makefile,v 1.9 2022/06/28 11:35:14 wiz Exp $
#

DISTNAME=	Net-Stomp-0.61
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

HOMEPAGE=	https://metacpan.org/release/Net-Stomp
COMMENT=	Streaming Text Orientated Messaging Protocol Client
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Log-Any>=1.70.7:../../devel/p5-Log-Any
DEPENDS+=	p5-Log-Any-Adapter-TAP-[0-9]*:../../devel/p5-Log-Any-Adapter-TAP

TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-NiceDump-[0-9]*:../../devel/p5-Test-NiceDump

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Net/Stomp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
