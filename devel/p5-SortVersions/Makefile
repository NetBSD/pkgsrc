# $NetBSD: Makefile,v 1.6 2003/07/21 16:43:41 martti Exp $
#

DISTNAME=		SortVersions-1.1
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5sve
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Sort/}

MAINTAINER=		mcr@NetBSD.org
#HOMEPAGE=	
COMMENT=		Perl5 module for sorting of revision-like numbers

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Sort/Versions/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
