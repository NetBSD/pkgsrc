# $NetBSD: Makefile,v 1.28 2004/11/28 23:04:15 wiz Exp $
#

VERS=			3.05
DISTNAME=		MIME-Base64-${VERS}
PKGNAME=		p5-MIME-Base64-${VERS}
SVR4_PKGNAME=		p5mba
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/MIME-Base64/
COMMENT=		Perl5 module for Base64 and Quoted-Printable encodings

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MIME/Base64/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
