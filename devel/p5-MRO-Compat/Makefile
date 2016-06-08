# $NetBSD: Makefile,v 1.15 2016/06/08 19:23:08 wiz Exp $

DISTNAME=	MRO-Compat-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BO/BOBTFISH/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?MRO::Compat
COMMENT=	MRO::* interface compatibility for Perls < 5.9.5
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MRO/Compat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
