# $NetBSD: Makefile,v 1.17 2002/10/20 17:46:00 seb Exp $
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

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MIME/Base64/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
