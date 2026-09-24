# $NetBSD: Makefile,v 1.26 2026/09/24 13:10:12 wiz Exp $

DISTNAME=	Clone-PP-1.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NE/NEILB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Clone-PP
COMMENT=	Recursively copy Perl datatypes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Clone/PP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
