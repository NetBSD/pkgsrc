# $NetBSD: Makefile,v 1.18 2011/08/14 12:26:21 obache Exp $
#

DISTNAME=	MooseX-Getopt-0.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Getopt/
COMMENT=	Perl 5 Moose role for processing command line options
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Getopt-Long-Descriptive>=0.081:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=	p5-Moose>=0.56:../../devel/p5-Moose

BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Requires>=0.05:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Warn>=0.21:../../devel/p5-Test-Warn

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Getopt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
