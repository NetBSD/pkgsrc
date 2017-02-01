# $NetBSD: Makefile,v 1.2 2017/02/01 13:36:15 mef Exp $

DISTNAME=	IO-Event-0.813
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MU/MUIR/modules/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MU/MUIR/modules/
COMMENT=	Tied Filehandles for Nonblocking IO with Object Callbacks
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=  # empty
PERL5_PACKLIST= auto/IO/Event/.packlist
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
