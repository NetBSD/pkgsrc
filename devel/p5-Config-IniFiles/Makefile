# $NetBSD: Makefile,v 1.7 2003/07/17 21:32:11 grant Exp $
#

DISTNAME=	Config-IniFiles-2.23
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cif
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/config-inifiles/
COMMENT=	Perl module for reading .ini-style configuration files

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Config/IniFiles/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
