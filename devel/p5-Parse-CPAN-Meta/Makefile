# $NetBSD: Makefile,v 1.9 2012/07/05 16:32:41 sno Exp $

DISTNAME=	Parse-CPAN-Meta-1.4404
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Parse-CPAN-Meta/
COMMENT=	Perl5 module to parse META.yml and other similar CPAN metadata files
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	{perl>=5.6.0,p5-PathTools>=0.80}:../../devel/p5-PathTools

DEPENDS+=	{perl>=5.16.0,p5-JSON-PP>=2.27200}:../../converters/p5-JSON-PP
DEPENDS+=	{perl>=5.17.1,p5-CPAN-Meta-YAML>=0.008}:../../devel/p5-CPAN-Meta-YAML

BUILD_DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	{perl>=5.6.0,p5-ExtUtils-MakeMaker>=0.30}:../../devel/p5-ExtUtils-MakeMaker

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Parse/CPAN/Meta/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
