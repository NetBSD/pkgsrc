# $NetBSD: Makefile,v 1.1 2020/09/07 20:06:20 otis Exp $

DISTNAME=		PkgConfig-0.24026
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PL/PLICEASE/}

MAINTAINER=		otis@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/PkgConfig
COMMENT=		Pure-Perl Core-Only replacement for pkg-config
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/PkgConfig/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
