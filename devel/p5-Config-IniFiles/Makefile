# $NetBSD: Makefile,v 1.11 2005/04/11 21:45:30 tv Exp $
#

DISTNAME=	Config-IniFiles-2.38
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cif
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/config-inifiles/
COMMENT=	Perl module for reading .ini-style configuration files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Config/IniFiles/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
