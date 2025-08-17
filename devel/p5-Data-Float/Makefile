# $NetBSD: Makefile,v 1.4 2025/08/17 09:30:50 wiz Exp $

DISTNAME=	Data-Float-0.015
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Data::Float
COMMENT=	Perl module for floating point data
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Carp>=0:../../devel/p5-Carp

PERL5_PACKLIST=		auto/Data/Float/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
