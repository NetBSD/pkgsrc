# $NetBSD: Makefile,v 1.1.1.1 2012/01/25 09:27:07 hiramatsu Exp $

DISTNAME=	Net-Frame-Dump-1.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Base class for a tcpdump-like implementation
HOMEPAGE=	http://search.cpan.org/dist/Net-Frame-Dump/
LICENSE=	artistic

DEPENDS+=	p5-Class-Gomor>=1.0:../../devel/p5-Class-Gomor
DEPENDS+=	p5-Net-Pcap>=0.12:../../net/p5-Net-Pcap
DEPENDS+=	p5-Net-Frame-[0-9]*:../../net/p5-Net-Frame

PKG_INSTALLATION_TYPES=		overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Net/Frame/Dump/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
