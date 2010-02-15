# $NetBSD: Makefile,v 1.5 2010/02/15 14:33:03 sno Exp $

DISTNAME=	Data-Page-2.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Page/
COMMENT=	Pager utility for Class::DBI
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor-Chained>=0:../../devel/p5-Class-Accessor-Chained
BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception

PERL5_MODULE_TYPE=	Module::Build
USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Data/Page/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
