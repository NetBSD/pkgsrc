# $NetBSD: Makefile,v 1.8 2017/06/05 14:23:49 ryoon Exp $
#

DISTNAME=	Tie-Function-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-Function/
COMMENT=	Wrap functions in tied hash sugar
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Tie/Function/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
