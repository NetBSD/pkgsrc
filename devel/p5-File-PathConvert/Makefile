# $NetBSD: Makefile,v 1.4 2001/10/18 15:20:15 veego Exp $
#

DISTNAME=	File-PathConvert-0.85
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fpc
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/File-PathConvert/
COMMENT=	Convert paths and URLs from absolute to relative and vice versa

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/File/PathConvert/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
