# $NetBSD: Makefile,v 1.5 2003/07/17 22:53:05 grant Exp $
#

DISTNAME=		Digest-HMAC-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5sh2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		perl5 module for HMAC

DEPENDS+=		p5-Digest-SHA1>=1.00:../p5-Digest-SHA1
DEPENDS+=		p5-Digest-MD5>=2.00:../p5-Digest-MD5

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/HMAC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
