# $NetBSD: Makefile,v 1.1.1.1 2001/08/10 12:25:04 mjl Exp $
#

DISTNAME=	Config-IniFiles-2.19
PKGNAME=	p5-${DISTNAME}
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
