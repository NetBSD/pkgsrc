# $NetBSD: Makefile,v 1.10 2003/12/10 22:00:28 heinz Exp $
#

DISTNAME=		Digest-MD2-2.03
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5md2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module for MD2

CONFLICTS+=		p5-Digest-MD5<=2.12

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/MD2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
