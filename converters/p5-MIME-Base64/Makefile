# $NetBSD: Makefile,v 1.10 1999/05/13 01:39:32 bad Exp $
# FreeBSD Id: Makefile,v 1.3 1997/08/04 22:47:16 ache Exp
#

DISTNAME=		MIME-Base64-2.11
PKGNAME=		p5-MIME-Base64-2.11
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MIME/}


MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/MIME-Base64/Base64.html

USE_PERL5=		yes

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
