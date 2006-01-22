# $NetBSD: Makefile,v 1.19 2006/01/22 20:31:29 wiz Exp $
#

DISTNAME=		Digest-SHA1-2.11
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5sh2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Digest-SHA1/
COMMENT=		Perl5 module for SHA1

DEPENDS+=		p5-Digest>=1.00:../../security/p5-Digest

CONFLICTS+=		p5-Digest-MD5<=2.12

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Digest/SHA1/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
