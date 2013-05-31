# $NetBSD: Makefile,v 1.27 2013/05/31 12:40:16 wiz Exp $

DISTNAME=	Devel-SmallProf-2.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5dsp
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-SmallProf/
COMMENT=	Perl5 module for line-by-line profiling perl programs
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Time-HiRes>=1.20:../../time/p5-Time-HiRes

PERL5_PACKLIST=		auto/Devel/SmallProf/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
