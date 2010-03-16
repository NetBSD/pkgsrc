# $NetBSD: Makefile,v 1.5 2010/03/16 23:54:36 sno Exp $
#

DISTNAME=	Getopt-Euclid-0.2.1
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Getopt-Euclid/
COMMENT=	Perl 5 module to create command-line parser from documentation
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{perl>=5.10.0,p5-version-[0-9]*}:../../devel/p5-version

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Getopt/Euclid/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
