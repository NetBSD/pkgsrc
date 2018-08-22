# $NetBSD: Makefile,v 1.20 2018/08/22 09:43:50 wiz Exp $

DISTNAME=	Data-OptList-0.110
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-OptList/
COMMENT=	Parse and validate simple name/value option pairs
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Data/OptList/.packlist

DEPENDS+=	p5-Params-Util>=0.14:../../devel/p5-Params-Util
DEPENDS+=	p5-Sub-Install>=0.921:../../devel/p5-Sub-Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
