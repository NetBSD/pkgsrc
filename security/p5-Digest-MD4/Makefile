# $NetBSD: Makefile,v 1.5 2003/06/02 01:17:08 jschauma Exp $
#

DISTNAME=		Digest-MD4-1.1
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5md4
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		tech-pkg@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module for MD4 hash algorithm

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/MD4/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
