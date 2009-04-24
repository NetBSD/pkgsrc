# $NetBSD: Makefile,v 1.11 2009/04/24 17:15:21 sno Exp $
#

DISTNAME=	SQL-Abstract-1.51
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sqa
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SQL-Abstract/
COMMENT=	Generate SQL from Perl data structures

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=0}:../../devel/p5-Scalar-List-Utils
BUILD_DEPENDS+=	{perl>=5.10,p5-Test-Simple>0}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

PERL5_PACKLIST=		auto/SQL/Abstract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
