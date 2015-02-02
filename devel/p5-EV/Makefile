# $NetBSD: Makefile,v 1.16 2015/02/02 10:25:35 jperkin Exp $

DISTNAME=	EV-4.18
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/ML/MLEHMANN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/EV/
COMMENT=	Perl interface to libev, a high performance full-featured event loop
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

MAKE_ENV+=	PERL_MM_USE_DEFAULT=1
PERL5_PACKLIST=	auto/EV/.packlist

OPSYSVARS+=	MAKE_ENV

# Explicitly disable inotify on SunOS, assumes Linux statfs.
MAKE_ENV.SunOS+=	EV_INOTIFY=0

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
