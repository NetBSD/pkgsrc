# $NetBSD: Makefile,v 1.5 2002/10/06 22:31:07 seb Exp $
#

DISTNAME=		Digest-MD2-2.00
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5md2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module for MD2

CONFLICTS+=		p5-Digest-MD5<=2.12

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/MD2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
