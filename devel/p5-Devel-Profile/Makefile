# $NetBSD: Makefile,v 1.2 2004/04/27 03:09:58 snj Exp $

DISTNAME=	Devel-Profile-1.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~jaw/Devel-Profile-1.03/Profile.pm
COMMENT=	Perl5 module for profiling perl programs

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Devel/Profile/.packlist

DEPENDS+=	p5-Time-HiRes>=1.20:../../time/p5-Time-HiRes

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
