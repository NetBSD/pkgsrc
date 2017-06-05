# $NetBSD: Makefile,v 1.7 2017/06/05 14:23:51 ryoon Exp $

DISTNAME=	Types-Serialiser-1.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/ML/MLEHMANN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Types-Serialiser/
COMMENT=	Simple data types for common serialisation formats

BUILD_DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

LICENSE=		${PERL5_LICENSE}
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Types/Serialiser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
