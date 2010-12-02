# $NetBSD: Makefile,v 1.43 2010/12/02 12:11:04 wiz Exp $
#

DISTNAME=		MIME-Base64-3.13
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mba
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/MIME-Base64/
COMMENT=		Perl5 module for Base64 and Quoted-Printable encodings
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/MIME/Base64/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
