# $NetBSD: Makefile,v 1.2 2002/10/20 17:46:05 seb Exp $
#

DISTNAME=		IO-Socket-Multicast-0.25
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ism
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		he@netbsd.org
COMMENT=		IO::Socket::Multicast - perl multicast socket IO

DEPENDS+=		p5-IO-Interface>=0.94:../../net/p5-IO-Interface

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Socket/Multicast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
