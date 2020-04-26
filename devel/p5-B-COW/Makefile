# $NetBSD: Makefile,v 1.1 2020/04/26 13:31:28 mef Exp $

DISTNAME=	B-COW-0.004
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/A/AT/ATOOMIC/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/A/AT/ATOOMIC/
COMMENT=	Some naive additional B helpers to check the COW status of one SvPV
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/B/COW/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
