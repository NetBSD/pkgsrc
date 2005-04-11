# $NetBSD: Makefile,v 1.13 2005/04/11 21:47:16 tv Exp $
#

DISTNAME=		Digest-MD4-1.5
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5md4
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Digest-MD4/
COMMENT=		Perl5 module for MD4 hash algorithm

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/MD4/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
