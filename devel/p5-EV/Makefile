# $NetBSD: Makefile,v 1.33 2020/04/11 12:03:53 mef Exp $

DISTNAME=	EV-4.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/ML/MLEHMANN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/EV
COMMENT=	Perl interface to libev, a high performance full-featured event loop
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense
DEPENDS+=	p5-Canary-Stability-[0-9]*:../../devel/p5-Canary-Stability

MAKE_ENV+=	PERL_MM_USE_DEFAULT=1
PERL5_PACKLIST=	auto/EV/.packlist

# Explicitly disable epoll and inotify on illumos, assumes Linux statfs.
MAKE_ENV.SunOS+=	EV_EPOLL=0 EV_INOTIFY=0

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
