# $NetBSD: Makefile,v 1.10 2005/04/11 21:47:15 tv Exp $
#

DISTNAME=		Crypt-RIPEMD160-0.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cri
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-RIPEMD160/
COMMENT=		Perl5 module of the RIPEMD160 hash function

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/RIPEMD160/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
