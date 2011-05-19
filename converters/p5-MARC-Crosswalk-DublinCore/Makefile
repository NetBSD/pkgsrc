# $NetBSD: Makefile,v 1.2 2011/05/19 05:27:30 obache Exp $

DISTNAME=	MARC-Crosswalk-DublinCore-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MARC-Crosswalk-DublinCore/
COMMENT=	Convert data between MARC and Dublin Core
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DublinCore-Record-[0-9]*:../../databases/p5-DublinCore-Record

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MARC/Crosswalk/DublinCore/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
