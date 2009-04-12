# $NetBSD: Makefile,v 1.20 2009/04/12 19:30:04 sno Exp $
#

DISTNAME=	Config-IniFiles-2.48
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cif
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/config-inifiles/
#HOMEPAGE=	http://search.cpan.org/dist/Config-IniFiles/
COMMENT=	Perl module for reading .ini-style configuration files
LICENSE=	artistic-2.0

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Config/IniFiles/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
