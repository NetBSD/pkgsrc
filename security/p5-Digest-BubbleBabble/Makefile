# $NetBSD: Makefile,v 1.2 2004/04/27 05:44:22 snj Exp $
#

DISTNAME=		Digest-BubbleBabble-0.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5bbl
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/author/BTROTT/Digest-BubbleBabble/
COMMENT=		Perl5 module for bubble babble fingerprints

DEPENDS+=		p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/BubbleBabble/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
