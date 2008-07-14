# $NetBSD: Makefile,v 1.1.1.1 2008/07/14 09:35:11 abs Exp $

DISTNAME=	SQL-Translator-0.09000
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/J/JR/JROBINSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?SQL::Translator
COMMENT=	Manipulate structured data definitions (SQL and more)

DEPENDS+=	p5-Class-Base>=0:../../devel/p5-Class-Base
DEPENDS+=	p5-Class-Data-Inheritable>=0.02:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Class-MakeMethods>=0:../../devel/p5-Class-MakeMethods
DEPENDS+=	p5-Log-Log4perl>=0:../../devel/p5-Log-Log4perl
DEPENDS+=	p5-Parse-RecDescent>=1.94:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-DBI>=0:../../databases/p5-DBI

BUILD_DEPENDS+=	p5-PathTools>=0:../../devel/p5-PathTools
BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Differences>=0:../../devel/p5-Test-Differences
BUILD_DEPENDS+=	p5-YAML>=0.39:../../textproc/p5-YAML

USE_LANGUAGES=	# empty
PERL5_MODULE_TYPE= Module::Build
PERL5_PACKLIST=	auto/SQL/Translator/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
