# $NetBSD: Makefile,v 1.17 2010/02/16 13:23:21 sno Exp $
#

DISTNAME=	SQL-Abstract-1.61
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sqa
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SQL-Abstract/
COMMENT=	Generate SQL from Perl data structures
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=0}:../../devel/p5-Scalar-List-Utils

BUILD_DEPENDS+=	p5-Clone>=0.31:../../devel/p5-Clone
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	{perl>=5.10,p5-Test-Simple>0}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

PERL5_PACKLIST=		auto/SQL/Abstract/.packlist
PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
