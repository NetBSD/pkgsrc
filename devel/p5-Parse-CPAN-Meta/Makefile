# $NetBSD: Makefile,v 1.1 2009/03/01 22:09:26 sno Exp $
#

DISTNAME=	Parse-CPAN-Meta-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Parse-CPAN-Meta/
COMMENT=	Perl5 module to parse META.yml and other similar CPAN metadata files

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Parse/CPAN/Meta/.packlist

DEPENDS+=	{perl>=5.6.0,p5-PathTools>=0.80}:../../devel/p5-PathTools
BUILD_DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	{perl>=5.6.0,p5-ExtUtils-MakeMaker>=0.30}:../../devel/p5-ExtUtils-MakeMaker

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
