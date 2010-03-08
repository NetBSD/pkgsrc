# $NetBSD: Makefile,v 1.13 2010/03/08 16:57:36 sno Exp $
#

DISTNAME=	MooseX-Getopt-0.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Getopt/
COMMENT=	Perl 5 Moose role for processing command line options
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.10,p5-Getopt-Long>=2.37}:../../devel/p5-Getopt-Long
DEPENDS+=	p5-Getopt-Long-Descriptive>=0.081:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=	p5-Moose>=0.56:../../devel/p5-Moose

BUILD_DEPENDS+=	p5-MooseX-ConfigFromFile-[0-9]*:../../devel/p5-MooseX-ConfigFromFile
BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Getopt/.packlist
MAKE_PARAMS+=	--skipdeps

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
