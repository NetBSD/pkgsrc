# $NetBSD: Makefile,v 1.20 2017/06/05 14:24:22 ryoon Exp $
#

DISTNAME=	Net-Telnet-Cisco-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Telnet-Cisco/
COMMENT=	Perl5 module for communicating with Cisco routers via telnet

PERL5_PACKLIST=		auto/Net/Telnet/Cisco/.packlist

DEPENDS+=		p5-Net-Telnet>=3.0:../../net/p5-Net-Telnet
DEPENDS+=		p5-Term-ReadKey>=2.0:../../devel/p5-Term-ReadKey
#DEPENDS+=		{perl>=5.8.0,p5-Test-Simple>=0.4}:../../devel/p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
