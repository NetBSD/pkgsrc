# $NetBSD: Makefile,v 1.15 2013/05/31 12:41:53 wiz Exp $
#

DISTNAME=		Crypt-CAST5_PP-1.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
SVR4_PKGNAME=		p5cca
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-CAST5_PP/
COMMENT=		The CAST5 block cipher, implemented in pure Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/CAST5_PP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
