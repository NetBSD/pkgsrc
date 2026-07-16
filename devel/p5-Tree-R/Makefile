# $NetBSD: Makefile,v 1.12 2026/07/16 19:03:41 wiz Exp $

DISTNAME=	Tree-R-0.072
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tree/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Tree-R
COMMENT=	Perl extension for the Rtree data structure and algorithms
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Tree/R/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
