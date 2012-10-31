# $NetBSD: Makefile,v 1.3 2012/10/31 11:19:13 asau Exp $
#

DISTNAME=	Tie-Function-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
