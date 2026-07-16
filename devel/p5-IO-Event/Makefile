# $NetBSD: Makefile,v 1.15 2026/07/16 19:02:36 wiz Exp $

DISTNAME=	IO-Event-0.813
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MU/MUIR/modules/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-Event
COMMENT=	Tied Filehandles for Nonblocking IO with Object Callbacks
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=  # empty
PERL5_PACKLIST= auto/IO/Event/.packlist
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
