# $NetBSD: Makefile,v 1.3 2005/04/11 21:47:15 tv Exp $
#

DISTNAME=		Crypt-CAST5_PP-1.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cca
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-CAST5_PP/
COMMENT=		The CAST5 block cipher, implemented in pure Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/CAST5_PP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
