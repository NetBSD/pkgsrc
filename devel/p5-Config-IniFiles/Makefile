# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:13 veego Exp $
#

DISTNAME=	Config-IniFiles-2.19
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cif
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/config-inifiles/
COMMENT=	Perl module for reading .ini-style configuration files

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Config/IniFiles/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
