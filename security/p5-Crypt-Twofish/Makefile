# $NetBSD: Makefile,v 1.8 2004/02/24 22:29:40 heinz Exp $
#

DISTNAME=		Crypt-Twofish-2.12
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ctw
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-Twofish/
COMMENT=		Perl5 module for the Twofish symmetric key algorithm

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/Twofish/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
