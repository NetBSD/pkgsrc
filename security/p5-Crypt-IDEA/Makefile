# $NetBSD: Makefile,v 1.6 2004/02/22 17:07:18 heinz Exp $
#

DISTNAME=		Crypt-IDEA-1.02
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-IDEA/
COMMENT=		Perl5 module for the IDEA symmetric key algorithm

# IDEA's license
LICENCE=		fee-based-commercial-use

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/IDEA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
