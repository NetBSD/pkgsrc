# $NetBSD: Makefile,v 1.9 2004/12/05 16:56:37 he Exp $
#

DISTNAME=	Config-IniFiles-2.38
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cif
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/config-inifiles/
COMMENT=	Perl module for reading .ini-style configuration files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Config/IniFiles/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
