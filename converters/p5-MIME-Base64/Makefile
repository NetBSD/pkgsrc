# $NetBSD: Makefile,v 1.26 2004/05/02 02:13:26 heinz Exp $
#

VERS=			3.01
DISTNAME=		MIME-Base64-${VERS}
PKGNAME=		p5-MIME-Base64-${VERS}
SVR4_PKGNAME=		p5mba
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/MIME-Base64/Base64.html
COMMENT=		Perl5 module for Base64 and Quoted-Printable encodings

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MIME/Base64/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
