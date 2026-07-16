# $NetBSD: Makefile,v 1.16 2026/07/16 19:02:38 wiz Exp $
#

DISTNAME=	IO-Pipely-0.006
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-Pipely
COMMENT=	Portably create pipe() or pipe-like handles, one way or another
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/IO/Pipely/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
