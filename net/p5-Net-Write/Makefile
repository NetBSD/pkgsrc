# $NetBSD: Makefile,v 1.21 2019/06/30 20:16:32 nia Exp $
#

DISTNAME=	Net-Write-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Write
COMMENT=	Portable interface to open and send raw data to network
LICENSE=	artistic

DEPENDS+=	p5-Class-Gomor-[0-9]*:../../devel/p5-Class-Gomor
DEPENDS+=	p5-Net-Pcap>=0.12:../../net/p5-Net-Pcap
DEPENDS+=	p5-Socket6-[0-9]*:../../net/p5-Socket6

PERL5_PACKLIST=	auto/Net/Write/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
