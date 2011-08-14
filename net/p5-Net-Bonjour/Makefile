# $NetBSD: Makefile,v 1.3 2011/08/14 14:14:42 obache Exp $
#

DISTNAME=		Net-Bonjour-0.96
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Net-Bonjour/
COMMENT=		Module for DNS service discovery (Apple's Bonjour/Rendezvous)
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Net-DNS>=0.50:../../net/p5-Net-DNS

SUPERSEDES+=		p5-Net-Rendezvous-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Net/Bonjour/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
