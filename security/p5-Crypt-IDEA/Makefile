# $NetBSD: Makefile,v 1.3 2003/06/02 01:17:12 jschauma Exp $
#

DISTNAME=		Crypt-IDEA-1.01
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		tech-pkg@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module for the IDEA symmetric key algorithm

USE_BUILDLINK2=		YES

# IDEA's license
LICENCE=		fee-based-commercial-use

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/IDEA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
