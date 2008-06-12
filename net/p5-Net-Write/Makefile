# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:40 joerg Exp $
#

DISTNAME=	Net-Write-1.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/G/GO/GOMOR/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/G/GO/GOMOR/
COMMENT=	Portable interface to open and send raw data to network

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Gomor-[0-9]*:../../devel/p5-Class-Gomor
DEPENDS+=	p5-Net-Pcap>=0.12:../../net/p5-Net-Pcap
DEPENDS+=	p5-Socket6-[0-9]*:../../net/p5-Socket6

PERL5_PACKLIST=	auto/Net/Write/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
