# $NetBSD: Makefile,v 1.22.2.1 2003/12/05 17:38:47 agc Exp $
#

VERS=			2.21
DISTNAME=		MIME-Base64-${VERS}
PKGNAME=		p5-MIME-Base64-${VERS}
SVR4_PKGNAME=		p5mba
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/MIME-Base64/Base64.html
COMMENT=		Perl5 module for Base64 and Quoted-Printable encodings

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MIME/Base64/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
