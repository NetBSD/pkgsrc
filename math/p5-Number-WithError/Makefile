# $NetBSD: Makefile,v 1.7 2023/07/06 09:40:55 wiz Exp $

DISTNAME=	Number-WithError-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Number-WithError
COMMENT=	Numbers with error propagation and scientific rounding
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Params-Util-[0-9]*:../../devel/p5-Params-Util
DEPENDS+=	p5-prefork-[0-9]*:../../devel/p5-prefork
TEST_DEPENDS+=	p5-Test-LectroTest-[0-9]*:../../devel/p5-Test-LectroTest

PERL5_PACKLIST=		auto/Number/WithError/.packlist

PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
