# $NetBSD: Makefile,v 1.10 2016/05/27 13:24:43 wen Exp $
#

DISTNAME=	Pod-Usage-1.69
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Usage/
COMMENT=	Print a usage message from embedded pod documentation
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-podlators>=4.0:../../textproc/p5-podlators

EXTRACT_USING=	gtar

PERL5_PACKLIST=	auto/Pod/Usage/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
