# $NetBSD: Makefile,v 1.4 2016/06/08 19:23:03 wiz Exp $
#

DISTNAME=	IO-Pipely-0.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Pipely/
COMMENT=	Portably create pipe() or pipe-like handles, one way or another
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/IO/Pipely/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
