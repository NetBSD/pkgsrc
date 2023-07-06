# $NetBSD: Makefile,v 1.29 2023/07/06 09:39:03 wiz Exp $

DISTNAME=	Devel-Profile-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-Profile
COMMENT=	Perl5 module for profiling perl programs
LICENSE=	artistic

#DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes>=1.20}:../../time/p5-Time-HiRes

PERL5_PACKLIST=		auto/Devel/Profile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
