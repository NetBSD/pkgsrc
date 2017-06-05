# $NetBSD: Makefile,v 1.15 2017/06/05 14:23:58 ryoon Exp $

DISTNAME=	Data-Currency-0.06000
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Data::Currency
COMMENT=	Container class for currency conversion/formatting
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor-Grouped>=0.03:../../devel/p5-Class-Accessor-Grouped
DEPENDS+=	p5-Class-Inspector>=0:../../devel/p5-Class-Inspector
DEPENDS+=	p5-Finance-Currency-Convert-WebserviceX>=0.03:../../finance/p5-Finance-Currency-Convert-WebserviceX
#DEPENDS+=	{perl>=5.13.1,p5-Locale-Codes>=2.07}:../../misc/p5-Locale-Codes
DEPENDS+=	p5-Locale-Currency-Format>=1.22:../../finance/p5-Locale-Currency-Format
#DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=0}:../../devel/p5-Scalar-List-Utils

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Data/Currency/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
