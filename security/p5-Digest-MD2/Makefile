# $NetBSD: Makefile,v 1.13 2005/04/11 21:47:16 tv Exp $
#

DISTNAME=		Digest-MD2-2.03
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5md2
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module for MD2

CONFLICTS+=		p5-Digest-MD5<=2.12

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/MD2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
