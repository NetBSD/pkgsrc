# $NetBSD: Makefile,v 1.13 2004/02/22 16:54:56 heinz Exp $
# FreeBSD Id: Makefile,v 1.7 1997/06/24 18:43:23 jfitz Exp
#

DISTNAME=		Crypt-CBC-2.08
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cbc
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-CBC/
COMMENT=		Perl5 cipher block chaining mode for various crypto algorithms

BUILD_DEPENDS+=		p5-Crypt-Rijndael-[0-9]*:../../security/p5-Crypt-Rijndael
DEPENDS+=		p5-Digest-MD5>=2.0:../../security/p5-Digest-MD5

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/CBC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
