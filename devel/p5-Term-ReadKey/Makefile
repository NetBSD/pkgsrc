# $NetBSD: Makefile,v 1.2 2001/02/16 14:38:53 wiz Exp $
#

DISTNAME=	TermReadKey-2.14
PKGNAME=	p5-Term-ReadKey-2.14
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/TermReadKey/
COMMENT=	Change terminal modes and perform non-blocking reads

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Term/ReadKey/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
