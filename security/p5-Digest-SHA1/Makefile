# $NetBSD: Makefile,v 1.9.2.1 2003/12/05 17:19:49 agc Exp $
#

DISTNAME=		Digest-SHA1-2.06
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5sh2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module for SHA1

CONFLICTS+=		p5-Digest-MD5<=2.12

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/SHA1/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
