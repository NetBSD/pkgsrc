# $NetBSD: Makefile,v 1.2 2020/08/31 18:07:29 wiz Exp $

DISTNAME=	B-COW-0.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/A/AT/ATOOMIC/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/A/AT/ATOOMIC/
COMMENT=	Some naive additional B helpers to check the COW status of one SvPV
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/B/COW/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
