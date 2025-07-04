# $NetBSD: Makefile,v 1.21 2025/07/04 08:47:27 wiz Exp $

DISTNAME=	Algorithm-Cluster-1.59
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Algorithm-Cluster
COMMENT=	Perl interface to the C Clustering Library
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Algorithm/Cluster/.packlist

MAKE_JOBS_SAFE=	no

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
