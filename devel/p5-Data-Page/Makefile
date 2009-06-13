# $NetBSD: Makefile,v 1.4 2009/06/13 06:46:44 rillig Exp $

DISTNAME=	Data-Page-2.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Page/
COMMENT=	Pager utility for Class::DBI

DEPENDS+=	p5-Class-Accessor-Chained>=0:../../devel/p5-Class-Accessor-Chained
BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception

PERL5_MODULE_TYPE=	Module::Build
USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Data/Page/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
