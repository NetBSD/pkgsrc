# $NetBSD: Makefile,v 1.12 2016/01/01 01:37:49 wen Exp $

DISTNAME=	autobox-Core-1.30
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=autobox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/autobox-Core/
COMMENT=	Perl 5 module adding core built-in functions in primitive types
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/autobox/Core/.packlist

DEPENDS+=	p5-autobox>=0.11:../../devel/p5-autobox

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
