# $NetBSD: Makefile,v 1.1.1.1 2004/09/04 14:02:33 seb Exp $
#

DISTNAME=		CipherSaber-0.60
PKGNAME=		p5-Crypt-${DISTNAME}
SVR4_PKGNAME=		p5ccs
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CipherSaber/
COMMENT=		Perl5 module for the CipherSaber encryptions

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/CipherSaber/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
