# $NetBSD: Makefile,v 1.5 2015/08/06 09:05:29 wiz Exp $

DISTNAME=		Digest-JHash-0.09
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Digest-JHash/
COMMENT=		Perl extension for 32 bit Jenkins Hashing Algorithm
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Digest/JHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
