# $NetBSD: Makefile,v 1.5 2009/04/12 20:18:37 sno Exp $
#

DISTNAME=	MooseX-Getopt-0.18
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Getopt/
COMMENT=	Perl 5 Moose role for processing command line options
LICENSE=	artistic-2.0

DEPENDS+=	p5-Getopt-Long-Descriptive-[0-9]*:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=	p5-Getopt-Long>=2.37:../../devel/p5-Getopt-Long
DEPENDS+=	p5-Moose>=0.43:../../devel/p5-Moose
BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Getopt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
