# $NetBSD: Makefile,v 1.11 2021/05/24 19:53:01 wiz Exp $

DISTNAME=		Number-Range-0.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Number-Range
COMMENT=		Define ranges and test if number is in range
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Number/Range/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
