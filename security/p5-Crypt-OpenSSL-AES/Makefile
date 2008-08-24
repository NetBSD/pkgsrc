# $NetBSD: Makefile,v 1.1.1.1 2008/08/24 09:09:38 obache Exp $
#

DISTNAME=		Crypt-OpenSSL-AES-0.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ose
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-OpenSSL-AES/
COMMENT=		Perl5 wrapper module for the OpenSSL AES functions

#LICENSE=		gnu-gpl-v2 # under same terms as Perl

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/Crypt/OpenSSL/AES/.packlist

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
