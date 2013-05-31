# $NetBSD: Makefile,v 1.6 2013/05/31 12:41:37 wiz Exp $
#

DISTNAME=		Net-Bonjour-0.96
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Net-Bonjour/
COMMENT=		Module for DNS service discovery (Apple's Bonjour/Rendezvous)
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Net-DNS>=0.50:../../net/p5-Net-DNS

SUPERSEDES+=		p5-Net-Rendezvous-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Net/Bonjour/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
