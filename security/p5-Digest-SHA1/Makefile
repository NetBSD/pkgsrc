# $NetBSD: Makefile,v 1.6 2003/06/02 01:17:07 jschauma Exp $
#

DISTNAME=		Digest-SHA1-2.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5sh2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		tech-pkg@netbsd.org
COMMENT=		perl5 module for SHA1

CONFLICTS+=		p5-Digest-MD5<=2.12

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/SHA1/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
