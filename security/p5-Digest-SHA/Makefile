# $NetBSD: Makefile,v 1.10 2006/06/07 20:14:23 heinz Exp $
#

DISTNAME=		Digest-SHA-5.41
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Digest-SHA/
COMMENT=		Perl module for SHA-1/224/256/384/512 algorithms

PERL5_PACKLIST=		auto/Digest/SHA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
