# $NetBSD: Makefile,v 1.5 2001/10/18 15:20:41 veego Exp $
#

DISTNAME=	Filter-1.16
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fil
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Filter/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl5 classes representing a number of source filters

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Filter/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
