# $NetBSD: Makefile,v 1.12 2023/07/06 09:40:51 wiz Exp $

DISTNAME=	Algorithm-Munkres-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Algorithm-Munkres
COMMENT=	Munkres Assignment for square and rectangular matrices
LICENSE=	gnu-gpl-v2

PERL5_PACKLIST=	auto/Algorithm/Munkres/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
