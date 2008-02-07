# $NetBSD: Makefile,v 1.14 2008/02/07 20:31:11 heinz Exp $
#

DISTNAME=		Crypt-DES-2.05
PKGNAME=		p5-Crypt-DES-2.05
SVR4_PKGNAME=		p5des
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-DES/
COMMENT=		XS-based DES implementation for Perl

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_DEPENDS+=		p5-Crypt-CBC-[0-9]*:../../security/p5-Crypt-CBC

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Crypt/DES/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
