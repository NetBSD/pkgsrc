# $NetBSD: Makefile,v 1.40 2021/05/24 19:50:33 wiz Exp $

DISTNAME=	Devel-SmallProf-2.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
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
