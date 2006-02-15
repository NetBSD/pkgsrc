# $NetBSD: Makefile,v 1.16 2006/02/15 20:42:54 heinz Exp $
#

DISTNAME=		Crypt-DSA-0.13
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dsa
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-DSA/
COMMENT=		Perl5 module for the DSA public key algorithm

DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=		p5-Data-Buffer-[0-9]*:../../devel/p5-Data-Buffer
DEPENDS+=		p5-Convert-PEM>=0.07:../../textproc/p5-Convert-PEM

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/DSA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
