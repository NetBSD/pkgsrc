# $NetBSD: Makefile,v 1.29 2023/07/06 09:41:11 wiz Exp $

DISTNAME=	Net-Telnet-Cisco-1.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Telnet-Cisco
COMMENT=	Perl5 module for communicating with Cisco routers via telnet

DEPENDS+=		p5-Net-Telnet>=3.0:../../net/p5-Net-Telnet
DEPENDS+=		p5-Term-ReadKey>=2.0:../../devel/p5-Term-ReadKey

PERL5_PACKLIST=		auto/Net/Telnet/Cisco/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
