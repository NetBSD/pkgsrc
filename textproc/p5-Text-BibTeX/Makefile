# $NetBSD: Makefile,v 1.1.1.1 2001/02/27 23:39:55 jtb Exp $

DISTNAME=	Text-BibTeX-0.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=biblio/bibtex/utils/btOOL/}
DISTFILES+=	${DISTNAME}.tar.gz btparse-0.32.tar.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://starship.python.net/~gward/btOOL/
COMMENT=	Perl library for reading, parsing, and processing BibTeX files

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Text/BibTeX/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
