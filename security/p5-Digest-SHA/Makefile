# $NetBSD: Makefile,v 1.1.1.1 2004/11/11 16:17:08 seb Exp $
#

DISTNAME=		Digest-SHA-5.27
PKGNAME=		p5-${DISTNAME}
#SVR4_PKGNAME=
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Digest-SHA/
COMMENT=		Perl module for SHA-1/224/256/384/512 algorithms

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/SHA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
