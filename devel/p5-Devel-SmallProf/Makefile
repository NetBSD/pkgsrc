# $NetBSD: Makefile,v 1.28 2013/12/09 14:17:44 obache Exp $

DISTNAME=	Devel-SmallProf-2.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
SVR4_PKGNAME=	p5dsp
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-SmallProf/
COMMENT=	Perl5 module for line-by-line profiling perl programs
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes>=1.20}:../../time/p5-Time-HiRes

PERL5_PACKLIST=		auto/Devel/SmallProf/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
