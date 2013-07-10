# $NetBSD: Makefile,v 1.49 2013/07/10 02:26:11 schmonz Exp $

DISTNAME=	MIME-Base64-3.14
PKGNAME=	p5-${DISTNAME}
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
