# $NetBSD: Makefile,v 1.7 2003/10/14 22:42:44 heinz Exp $
#

DISTNAME=		Digest-HMAC-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hmac
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module for HMAC

DEPENDS+=		p5-Digest-SHA1>=1.00:../p5-Digest-SHA1
DEPENDS+=		p5-Digest-MD5>=2.00:../p5-Digest-MD5

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/HMAC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
