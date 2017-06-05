# $NetBSD: Makefile,v 1.22 2017/06/05 14:22:53 ryoon Exp $

DISTNAME=	Devel-Profile-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Profile/
COMMENT=	Perl5 module for profiling perl programs
LICENSE=	artistic

#DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes>=1.20}:../../time/p5-Time-HiRes

PERL5_PACKLIST=		auto/Devel/Profile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
