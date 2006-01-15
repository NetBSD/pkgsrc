# $NetBSD: Makefile,v 1.1.1.1 2006/01/15 16:24:16 adrianp Exp $
#

DISTNAME=		Net-Rendezvous-0.90
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		adrianp@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~chlige/${DISTNAME}/
COMMENT=		Module for DNS service discovery (Apple's Rendezvous)

DEPENDS+=		p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Net/Rendezvous/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
