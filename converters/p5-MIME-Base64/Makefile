# $NetBSD: Makefile,v 1.15 2001/10/18 15:20:05 veego Exp $
# FreeBSD Id: Makefile,v 1.3 1997/08/04 22:47:16 ache Exp
#

VERS=			2.12
DISTNAME=		MIME-Base64-${VERS}
PKGNAME=		p5-MIME-Base64-${VERS}
SVR4_PKGNAME=		p5mba
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/MIME-Base64/Base64.html
COMMENT=		perl5 module for Base64 and Quoted-Printable encodings

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MIME/Base64/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
