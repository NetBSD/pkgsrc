# $NetBSD: Makefile,v 1.42 2023/07/06 09:39:03 wiz Exp $

DISTNAME=	Devel-SmallProf-2.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-SmallProf
COMMENT=	Perl5 module for line-by-line profiling perl programs
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes>=1.20}:../../time/p5-Time-HiRes

PERL5_PACKLIST=		auto/Devel/SmallProf/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
