# $NetBSD: Makefile,v 1.12 2020/08/31 18:09:11 wiz Exp $
#

DISTNAME=	Tie-Function-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Tie-Function
COMMENT=	Wrap functions in tied hash sugar
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Tie/Function/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
