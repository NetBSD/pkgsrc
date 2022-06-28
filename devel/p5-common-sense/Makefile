# $NetBSD: Makefile,v 1.29 2022/06/28 11:33:38 wiz Exp $

DISTNAME=	common-sense-3.75
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/ML/MLEHMANN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/common-sense
COMMENT=	Save a tree AND a kitten, use common::sense!
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/common/sense/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
