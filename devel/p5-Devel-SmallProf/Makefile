# $NetBSD: Makefile,v 1.15 2005/01/20 21:21:39 bad Exp $
#

DISTNAME=		Devel-SmallProf-1.15
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dsp
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		bad@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~salva/Devel-SmallProf-1.15/
COMMENT=		Perl5 module for line-by-line profiling perl programs

DEPENDS=		p5-Time-HiRes>=1.20:../../time/p5-Time-HiRes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Devel/SmallProf/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
