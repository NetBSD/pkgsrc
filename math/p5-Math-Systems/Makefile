# $NetBSD: Makefile,v 1.1 2018/06/20 05:04:59 mef Exp $

DISTNAME=	Math-Systems-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	http://www.cpan.org/authors/id/W/WI/WILL/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cpan.org/authors/id/W/WI/WILL/
COMMENT=	Solve simultaneous equation
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Math-Matrix-[0-9]*:../../math/p5-Math-Matrix
PERL5_PACKLIST=	auto/Math/Systems/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
