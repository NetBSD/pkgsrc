# $NetBSD: Makefile,v 1.48 2026/03/25 22:45:37 wiz Exp $

DISTNAME=	Clone-0.49
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AT/ATOOMIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Clone
COMMENT=	Perl module for recursively copying datatypes
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-B-COW-[0-9]*:../../devel/p5-B-COW

PERL5_PACKLIST=		auto/Clone/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
