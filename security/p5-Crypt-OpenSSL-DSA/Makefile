# $NetBSD: Makefile,v 1.17 2012/10/03 21:57:28 wiz Exp $
#

DISTNAME=		Crypt-OpenSSL-DSA-0.13
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
SVR4_PKGNAME=		p5ods
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://perl-openssl.sourceforge.net/
COMMENT=		Perl5 wrapper module for the OpenSSL DSA functions
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Crypt/OpenSSL/DSA/.packlist

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
