# $NetBSD: Makefile,v 1.10 2021/05/24 19:50:52 wiz Exp $
#

DISTNAME=	IO-Pipely-0.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
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
