# $NetBSD: Makefile,v 1.11 2011/08/14 12:26:35 obache Exp $

DISTNAME=	Schedule-RateLimiter-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Schedule/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module to schedule tasks with rate limiting

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty

DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes

PERL5_PACKLIST=	auto/Schedule/RateLimiter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
