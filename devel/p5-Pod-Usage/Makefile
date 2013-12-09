# $NetBSD: Makefile,v 1.3 2013/12/09 14:17:46 obache Exp $
#

DISTNAME=	Pod-Usage-1.61
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
