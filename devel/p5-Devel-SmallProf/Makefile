# $NetBSD: Makefile,v 1.10 2003/07/17 21:32:18 grant Exp $
#

DISTNAME=		Devel-SmallProf-0.9
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dsp
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		bad@NetBSD.org
COMMENT=		perl5 module for line-by-line profiling perl programs

DEPENDS=		p5-Time-HiRes>=01.20:../../time/p5-Time-HiRes

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Devel/SmallProf/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
