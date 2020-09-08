# $NetBSD: Makefile,v 1.4 2020/09/08 13:16:35 wiz Exp $

DISTNAME=	B-COW-0.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AT/ATOOMIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/B::COW
COMMENT=	Some naive additional B helpers to check the COW status of one SvPV
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/B/COW/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
