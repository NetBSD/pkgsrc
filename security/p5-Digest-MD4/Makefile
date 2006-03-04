# $NetBSD: Makefile,v 1.16 2006/03/04 21:30:37 jlam Exp $
#

DISTNAME=		Digest-MD4-1.5
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5md4
PKGREVISION=		2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Digest-MD4/
COMMENT=		Perl5 module for MD4 hash algorithm

PERL5_PACKLIST=		auto/Digest/MD4/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
