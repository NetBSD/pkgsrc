# $NetBSD: Makefile,v 1.4 2004/04/27 06:05:57 snj Exp $
#

DISTNAME=		IO-Socket-Multicast-0.25
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ism
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		he@NetBSD.org
COMMENT=		IO::Socket::Multicast - perl multicast socket IO

DEPENDS+=		p5-IO-Interface>=0.94:../../net/p5-IO-Interface

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Socket/Multicast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
