# $NetBSD: Makefile,v 1.7 2022/06/28 11:34:40 wiz Exp $

DISTNAME=	Math-Matrix-0.91
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PJ/PJACKLAM/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Math-Matrix
COMMENT=	Math::Matrix - Multiply and invert Matrices
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Math/Matrix/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
