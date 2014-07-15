# $NetBSD: Makefile,v 1.5 2014/07/15 20:38:04 schmonz Exp $
#

DISTNAME=	Pod-Usage-1.64
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Usage/
COMMENT=	Print a usage message from embedded pod documentation
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.17.9,p5-Pod-Parser>=1.60}:../../textproc/p5-Pod-Parser

PERL5_PACKLIST=	auto/Pod/Usage/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
