# $NetBSD: Makefile,v 1.1.1.1 2004/02/17 22:41:44 heinz Exp $
#

DISTNAME=		Net-CIDR-Lite-0.15
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ncl
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Net-CIDR-Lite/
COMMENT=		Perl extension for merging IPv4/v6 CIDR addresses

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/Net/CIDR/Lite/.packlist
USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
