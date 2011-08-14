# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:17 obache Exp $

DISTNAME=	Modern-Perl-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CH/CHROMATIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Modern-Perl/
COMMENT=	Enable all of the features of Modern Perl with one command
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Modern/Perl/.packlist
PERL5_MODULE_TYPE=	Module::Build
PERL5_REQD+=            5.10.0

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
