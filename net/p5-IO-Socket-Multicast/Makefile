# $NetBSD: Makefile,v 1.6 2005/04/11 21:46:53 tv Exp $
#

DISTNAME=		IO-Socket-Multicast-0.25
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ism
PKGREVISION=		1
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		he@NetBSD.org
COMMENT=		IO::Socket::Multicast - perl multicast socket IO

DEPENDS+=		p5-IO-Interface>=0.94:../../net/p5-IO-Interface

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Socket/Multicast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
