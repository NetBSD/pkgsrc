# $NetBSD: Makefile,v 1.18 2023/07/06 09:38:26 wiz Exp $

DISTNAME=	DublinCore-Record-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BR/BRICAS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DublinCore-Record
COMMENT=	Container for Dublin Core metadata elements
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DublinCore/Record/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
