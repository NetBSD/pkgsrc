# $NetBSD: Makefile,v 1.6 2019/08/11 13:19:37 wiz Exp $

DISTNAME=	IO-Event-0.813
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/M/MU/MUIR/modules/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/M/MU/MUIR/modules/
COMMENT=	Tied Filehandles for Nonblocking IO with Object Callbacks
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=  # empty
PERL5_PACKLIST= auto/IO/Event/.packlist
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
