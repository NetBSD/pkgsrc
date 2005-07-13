# $NetBSD: Makefile,v 1.14 2005/07/13 18:01:38 jlam Exp $
#

DISTNAME=		Crypt-DSA-0.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5dsa
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-DSA/
COMMENT=		Perl5 module for the DSA public key algorithm

DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=		p5-Math-Pari>=2.001804:../../math/p5-Math-Pari
DEPENDS+=		p5-Crypt-Random>=0.33:../../security/p5-Crypt-Random
DEPENDS+=		p5-Data-Buffer-[0-9]*:../../devel/p5-Data-Buffer
DEPENDS+=		p5-Convert-PEM-[0-9]*:../../textproc/p5-Convert-PEM
DEPENDS+=		p5-Class-Loader-[0-9]*:../../devel/p5-Class-Loader

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/DSA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
