# $NetBSD: Makefile,v 1.4 2019/08/11 13:22:23 wiz Exp $
#

DISTNAME=	Net-Stomp-0.57
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

HOMEPAGE=	https://metacpan.org/release/Net-Stomp
COMMENT=	Streaming Text Orientated Messaging Protocol Client
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Net/Stomp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
