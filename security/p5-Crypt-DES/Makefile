# $NetBSD: Makefile,v 1.10 2005/07/13 18:01:38 jlam Exp $
#

DISTNAME=		Crypt-DES-2.03
PKGNAME=		p5-Crypt-DES-2.03
SVR4_PKGNAME=		p5des
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-DES/
COMMENT=		XS-based DES implementation for Perl

BUILD_DEPENDS+=		p5-Crypt-CBC-[0-9]*:../../security/p5-Crypt-CBC

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Crypt/DES/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
