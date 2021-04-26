# $NetBSD: Makefile,v 1.13 2021/04/26 15:18:15 wiz Exp $

DISTNAME=	Types-Serialiser-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/ML/MLEHMANN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Types-Serialiser
COMMENT=	Simple data types for common serialisation formats

DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

LICENSE=		${PERL5_LICENSE}
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Types/Serialiser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
