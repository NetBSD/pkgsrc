# $NetBSD: Makefile,v 1.1.1.1 2004/04/12 14:20:57 grant Exp $

DISTNAME=	Schedule-RateLimiter-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Schedule/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module to schedule tasks with rate limiting

USE_BUILDLINK3=	yes
USE_LANGUAGES=	# empty

DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes

PERL5_CONFIGURE=YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Schedule/RateLimiter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
