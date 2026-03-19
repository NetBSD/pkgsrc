# $NetBSD: Makefile,v 1.47 2026/03/19 09:04:51 wiz Exp $

DISTNAME=	Clone-0.48
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AT/ATOOMIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Clone
COMMENT=	Perl module for recursively copying datatypes
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-B-COW-[0-9]*:../../devel/p5-B-COW

PERL5_PACKLIST=		auto/Clone/.packlist

# 0.48 distfile has extended attributes; needs fixing upstream
EXTRACT_USING=	gtar

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
