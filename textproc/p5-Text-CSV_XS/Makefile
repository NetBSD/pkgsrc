# $NetBSD: Makefile,v 1.2 2001/02/17 17:37:37 wiz Exp $
#

DISTNAME=	Text-CSV_XS-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	packages@netbsd.org
# HOMEPAGE=	http://
COMMENT=	Routines for composition and decomposition of comma-separated values

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Text/CSV_XS/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
