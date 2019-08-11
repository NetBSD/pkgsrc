# $NetBSD: Makefile,v 1.13 2019/08/11 13:18:13 wiz Exp $

DISTNAME=	MARC-Crosswalk-DublinCore-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	converters databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MARC-Crosswalk-DublinCore
COMMENT=	Convert data between MARC and Dublin Core
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DublinCore-Record-[0-9]*:../../databases/p5-DublinCore-Record

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MARC/Crosswalk/DublinCore/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
