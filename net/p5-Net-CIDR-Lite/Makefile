# $NetBSD: Makefile,v 1.4 2005/07/13 18:01:35 jlam Exp $
#

DISTNAME=		Net-CIDR-Lite-0.15
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ncl
PKGREVISION=		1
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Net-CIDR-Lite/
COMMENT=		Perl extension for merging IPv4/v6 CIDR addresses

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=         auto/Net/CIDR/Lite/.packlist
USE_LANGUAGES=		# empty

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
