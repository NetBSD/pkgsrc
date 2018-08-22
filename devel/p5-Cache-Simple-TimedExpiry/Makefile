# $NetBSD: Makefile,v 1.23 2018/08/22 09:43:40 wiz Exp $

DISTNAME=	Cache-Simple-TimedExpiry-0.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Cache-Simple-TimedExpiry/
COMMENT=	Perl module providing a lightweight cache with timed expiration
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Cache/Simple/TimedExpiry/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
