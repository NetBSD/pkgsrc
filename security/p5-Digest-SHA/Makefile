# $NetBSD: Makefile,v 1.5 2005/07/13 18:01:39 jlam Exp $
#

DISTNAME=		Digest-SHA-5.28
PKGNAME=		p5-${DISTNAME}
#SVR4_PKGNAME=
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Digest-SHA/
COMMENT=		Perl module for SHA-1/224/256/384/512 algorithms

PERL5_PACKLIST=		auto/Digest/SHA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
