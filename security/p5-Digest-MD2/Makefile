# $NetBSD: Makefile,v 1.11 2004/04/27 05:44:22 snj Exp $
#

DISTNAME=		Digest-MD2-2.03
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5md2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module for MD2

CONFLICTS+=		p5-Digest-MD5<=2.12

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/MD2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
