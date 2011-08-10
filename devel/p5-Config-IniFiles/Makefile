# $NetBSD: Makefile,v 1.29 2011/08/10 08:34:33 adam Exp $

DISTNAME=	Config-IniFiles-2.68
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cif
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-IniFiles/
COMMENT=	Perl module for reading .ini-style configuration files
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Config/IniFiles/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
