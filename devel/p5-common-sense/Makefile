# $NetBSD: Makefile,v 1.21 2016/06/08 19:23:46 wiz Exp $

DISTNAME=	common-sense-3.74
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/ML/MLEHMANN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/common-sense/
COMMENT=	Save a tree AND a kitten, use common::sense!
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/common/sense/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
