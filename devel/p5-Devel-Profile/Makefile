# $NetBSD: Makefile,v 1.3 2004/12/05 18:49:54 he Exp $

DISTNAME=	Devel-Profile-1.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Profile/
COMMENT=	Perl5 module for profiling perl programs

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Devel/Profile/.packlist

DEPENDS+=	p5-Time-HiRes>=1.20:../../time/p5-Time-HiRes

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
