# $NetBSD: Makefile,v 1.1.1.1 2004/11/12 14:22:12 he Exp $
#

DISTNAME=		Crypt-RandPasswd-0.02
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-RandPasswd/
COMMENT=		Random password generator based on FIPS-181

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/RandPasswd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
