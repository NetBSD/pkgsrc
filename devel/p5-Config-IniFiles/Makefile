# $NetBSD: Makefile,v 1.14 2006/03/04 21:29:20 jlam Exp $
#

DISTNAME=	Config-IniFiles-2.38
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cif
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/config-inifiles/
COMMENT=	Perl module for reading .ini-style configuration files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Config/IniFiles/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
