# $NetBSD: Makefile,v 1.5 2003/06/02 01:17:10 jschauma Exp $
#

DISTNAME=		Crypt-RIPEMD160-0.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cri
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		tech-pkg@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module of the RIPEMD160 hash function

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/RIPEMD160/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
