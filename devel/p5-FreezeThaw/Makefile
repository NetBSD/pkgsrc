# $NetBSD: Makefile,v 1.8 2004/02/17 23:55:38 heinz Exp $
#

DISTNAME=	FreezeThaw-0.43
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5frt
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FreezeThaw/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/FreezeThaw/
COMMENT=	Converting Perl structures to strings and back

USE_BUILDLINK3=		YES
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/FreezeThaw/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
