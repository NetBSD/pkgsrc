# $NetBSD: Makefile,v 1.1 2014/04/02 19:23:09 schmonz Exp $

DISTNAME=		Digest-JHash-0.08
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Digest-JHash/
COMMENT=		Perl extension for 32 bit Jenkins Hashing Algorithm
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Digest/JHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
