# $NetBSD: Makefile,v 1.32 2023/07/06 09:41:04 wiz Exp $
#

DISTNAME=		IO-Socket-Multicast-1.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		13
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/IO-Socket-Multicast
COMMENT=		Perl multicast socket IO
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-IO-Interface>=0.94:../../net/p5-IO-Interface

PERL5_PACKLIST=		auto/IO/Socket/Multicast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
