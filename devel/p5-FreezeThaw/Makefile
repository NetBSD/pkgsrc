# $NetBSD: Makefile,v 1.7 2003/07/21 16:43:38 martti Exp $
#

DISTNAME=	FreezeThaw-0.41
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5frt
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FreezeThaw/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Converting Perl structures to strings and back

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/FreezeThaw/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
