# $NetBSD: Makefile,v 1.1.1.1 2011/05/17 10:35:27 dmcmahill Exp $

DISTNAME=	MARC-Crosswalk-DublinCore-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BR/BRICAS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MARC-Crosswalk-DublinCore/
COMMENT=	Convert data between MARC and Dublin Core
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DublinCore-Record:../../databases/p5-DublinCore-Record

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MARC/Crosswalk/DublinCore/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
