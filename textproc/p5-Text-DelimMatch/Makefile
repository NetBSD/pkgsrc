# $NetBSD: Makefile,v 1.1.1.1 2000/09/04 21:49:08 kim Exp $
#

DISTNAME=	DelimMatch-1.03
PKGNAME=	p5-Text-DelimMatch-1.03
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/DelimMatch/

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Text/DelimMatch/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
