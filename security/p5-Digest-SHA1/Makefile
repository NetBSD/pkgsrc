# $NetBSD: Makefile,v 1.11 2003/12/10 22:12:32 heinz Exp $
#

DISTNAME=		Digest-SHA1-2.07
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5sh2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Digest-SHA1/
COMMENT=		Perl5 module for SHA1

DEPENDS+=		p5-Digest>=1.00:../p5-Digest

CONFLICTS+=		p5-Digest-MD5<=2.12

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/SHA1/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
