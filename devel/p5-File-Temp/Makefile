# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:16 veego Exp $
#

DISTNAME=	File-Temp-0.12
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fte
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	packages@netbsd.org
COMMENT=	provides functions for generating temporary files

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/File/Temp/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
