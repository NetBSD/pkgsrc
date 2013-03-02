# $NetBSD: Makefile,v 1.47 2013/03/02 10:44:33 tron Exp $

DISTNAME=	MIME-Base64-3.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5mba
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MIME-Base64/
COMMENT=	Perl5 module for Base64 and Quoted-Printable encodings
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/MIME/Base64/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
