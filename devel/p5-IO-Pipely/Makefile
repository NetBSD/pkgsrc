# $NetBSD: Makefile,v 1.9 2020/08/31 18:08:12 wiz Exp $
#

DISTNAME=	IO-Pipely-0.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
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
