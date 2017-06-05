# $NetBSD: Makefile,v 1.20 2017/06/05 14:23:34 ryoon Exp $

DISTNAME=	Schedule-RateLimiter-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Schedule/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module to schedule tasks with rate limiting

USE_LANGUAGES=	# empty

#DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes

PERL5_PACKLIST=	auto/Schedule/RateLimiter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
